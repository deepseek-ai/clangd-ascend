#!/bin/bash
set -euo pipefail

# Package a local release tarball.
#
# Usage:
#   ./scripts/release.sh                        # package only
#   ./scripts/release.sh --build-dir <path>      # custom build directory
#
# Prerequisites:
#   - build/bin/clangd must exist (run scripts/build-clangd.sh first)

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"

BUILD_DIR="${PROJECT_DIR}/build"

while [[ $# -gt 0 ]]; do
    case "$1" in
        --build-dir) BUILD_DIR="$2"; shift 2 ;;
        *)           echo "Unknown option: $1"; exit 1 ;;
    esac
done

# ---------- validate ----------
CLANGD_BIN="${BUILD_DIR}/bin/clangd"
RESOURCE_DIR="${BUILD_DIR}/lib/clang"
STUBS_DIR="${PROJECT_DIR}/include/cce_stubs"

if [[ ! -x "$CLANGD_BIN" ]]; then
    echo "ERROR: ${CLANGD_BIN} not found or not executable."
    echo "       Run scripts/build-clangd.sh first."
    exit 1
fi

if [[ ! -d "$RESOURCE_DIR" ]]; then
    echo "ERROR: ${RESOURCE_DIR} not found."
    exit 1
fi

for f in cce_stubs.h cce_builtin_stubs.h cce_intrinsic_stubs.h cce_simt_stubs.h stdint_stubs.h; do
    if [[ ! -f "${STUBS_DIR}/${f}" ]]; then
        echo "ERROR: ${STUBS_DIR}/${f} not found."
        exit 1
    fi
done

ARCH=$(uname -m)
TARBALL_NAME="ascend-clangd-${ARCH}.tar.gz"
OUT_DIR="${PROJECT_DIR}/dist"
TARBALL_PATH="${OUT_DIR}/${TARBALL_NAME}"

# ---------- assemble staging directory ----------
STAGING=$(mktemp -d /tmp/ascend-clangd-release-XXXXXX)
trap "rm -rf '$STAGING'" EXIT

echo "==> Assembling release package..."

# bin/clangd
mkdir -p "${STAGING}/bin"
cp "$CLANGD_BIN" "${STAGING}/bin/clangd"
chmod +x "${STAGING}/bin/clangd"

# include/cce_stubs/
mkdir -p "${STAGING}/include/cce_stubs"
# Package only the editor shims, never SDK headers from the build machine.
for f in cce_stubs.h cce_builtin_stubs.h cce_intrinsic_stubs.h cce_simt_stubs.h stdint_stubs.h; do
    cp "${STUBS_DIR}/${f}" "${STAGING}/include/cce_stubs/"
done
cp "${PROJECT_DIR}/LICENSE" "${PROJECT_DIR}/NOTICE" "${STAGING}/"
mkdir -p "${STAGING}/patches"
cp "${PROJECT_DIR}/patches/LICENSE" "${STAGING}/patches/LICENSE"

# lib/clang/<version>/include/ (clangd resource dir)
# Find the version directory (e.g. "23")
CLANG_VERSION_DIR=$(ls -1 "$RESOURCE_DIR" | head -1)
if [[ -z "$CLANG_VERSION_DIR" ]]; then
    echo "ERROR: no version directory under ${RESOURCE_DIR}"
    exit 1
fi
mkdir -p "${STAGING}/lib/clang/${CLANG_VERSION_DIR}"
cp -a "${RESOURCE_DIR}/${CLANG_VERSION_DIR}/include" "${STAGING}/lib/clang/${CLANG_VERSION_DIR}/include"

# ---------- create tarball ----------
mkdir -p "$OUT_DIR"
tar czf "$TARBALL_PATH" -C "$STAGING" .

SHA256=$(sha256sum "$TARBALL_PATH" | cut -d' ' -f1)

echo ""
echo "==> Release package created:"
echo "    File:   ${TARBALL_PATH}"
echo "    Size:   $(du -h "$TARBALL_PATH" | cut -f1)"
echo "    SHA256: ${SHA256}"

# ---------- verify tarball structure ----------
echo ""
echo "==> Tarball contents (top-level):"
tar tzf "$TARBALL_PATH" | grep -E '^\./(bin|include|lib)/' | sed 's|/[^/]*$|/|' | sort -u
