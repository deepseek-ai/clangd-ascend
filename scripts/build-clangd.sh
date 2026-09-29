#!/bin/bash
set -euo pipefail

# Build the custom clangd with Ascend CCE extensions.
# Prerequisites: cmake, ninja, gcc >= 13, ccache (optional)
#
# Usage:
#   ./scripts/build-clangd.sh [--llvm-dir <path>] [--build-dir <path>] [--jobs N]

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
PATCHES_DIR="${PROJECT_DIR}/patches"

LLVM_COMMIT="3056add6389b58656092edf9fed75ca6d55a9d9d"
LLVM_REPO="https://github.com/llvm/llvm-project.git"
LLVM_DIR=""
BUILD_DIR=""
JOBS=$(nproc)

while [[ $# -gt 0 ]]; do
    case "$1" in
        --llvm-dir)  LLVM_DIR="$2"; shift 2 ;;
        --build-dir) BUILD_DIR="$2"; shift 2 ;;
        --jobs)      JOBS="$2"; shift 2 ;;
        *)           echo "Unknown option: $1"; exit 1 ;;
    esac
done

[[ -z "$LLVM_DIR" ]] && LLVM_DIR="${PROJECT_DIR}/llvm-project"
[[ -z "$BUILD_DIR" ]] && BUILD_DIR="${PROJECT_DIR}/build"

# ---------- 1. Clone / checkout llvm-project ----------
if [[ ! -d "${LLVM_DIR}/.git" ]]; then
    echo "==> Cloning llvm-project (shallow) at ${LLVM_COMMIT}..."
    git clone --depth 1 "$LLVM_REPO" "$LLVM_DIR" --no-checkout
    git -C "$LLVM_DIR" fetch --depth 1 origin "$LLVM_COMMIT"
    git -C "$LLVM_DIR" checkout "$LLVM_COMMIT"
else
    echo "==> llvm-project already exists at ${LLVM_DIR}"
    CURRENT=$(git -C "$LLVM_DIR" rev-parse HEAD)
    if [[ "$CURRENT" != "$LLVM_COMMIT" ]]; then
        echo "    WARNING: HEAD is ${CURRENT}, expected ${LLVM_COMMIT}"
        echo "    Resetting..."
        git -C "$LLVM_DIR" fetch --depth 1 origin "$LLVM_COMMIT" 2>/dev/null || true
        git -C "$LLVM_DIR" checkout "$LLVM_COMMIT"
    fi
fi

# ---------- 2. Apply patches ----------
echo "==> Applying patches..."
for patch in "${PATCHES_DIR}"/*.patch; do
    if git -C "$LLVM_DIR" apply --check "$patch" 2>/dev/null; then
        git -C "$LLVM_DIR" apply "$patch"
        echo "    Applied: $(basename "$patch")"
    elif git -C "$LLVM_DIR" apply --reverse --check "$patch" 2>/dev/null; then
        echo "    Already applied: $(basename "$patch")"
    else
        echo "ERROR: patch conflicts with the LLVM checkout: $patch" >&2
        exit 1
    fi
done

# ---------- 3. Configure ----------
echo "==> Configuring build..."
HOST_TRIPLE=$(gcc -dumpmachine 2>/dev/null || echo "aarch64-unknown-linux-gnu")

CMAKE_ARGS=(
    -G Ninja
    -S "${LLVM_DIR}/llvm"
    -B "$BUILD_DIR"
    -DCMAKE_BUILD_TYPE=Release
    -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra"
    -DLLVM_TARGETS_TO_BUILD="AArch64"
    -DLLVM_DEFAULT_TARGET_TRIPLE="${HOST_TRIPLE}"
    -DLLVM_BUILD_STATIC=ON
    -DCMAKE_EXE_LINKER_FLAGS="-static"
    -DLLVM_ENABLE_ZLIB=OFF
    -DLLVM_ENABLE_ZSTD=OFF
    -DLLVM_ENABLE_TERMINFO=OFF
    -DLLVM_ENABLE_LIBXML2=OFF
    -DLLVM_STATIC_LINK_CXX_STDLIB=ON
)

# Use ccache if available
if command -v ccache &>/dev/null; then
    CMAKE_ARGS+=(-DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)
    echo "    Using ccache"
fi

cmake "${CMAKE_ARGS[@]}"

# ---------- 4. Build ----------
echo "==> Building clangd with ${JOBS} jobs..."
ninja -C "$BUILD_DIR" -j"$JOBS" clangd

echo ""
echo "==> Build complete!"
echo "    Binary: ${BUILD_DIR}/bin/clangd"
echo "    Size:   $(du -h "${BUILD_DIR}/bin/clangd" | cut -f1)"
echo "    SHA256: $(sha256sum "${BUILD_DIR}/bin/clangd" | cut -d' ' -f1)"
