#!/bin/bash
set -euo pipefail

# Install a local package archive.
# Usage: ./install.sh --package <archive> [--user] [--cann-path <path>]

INSTALL_DIR="${HOME}/.ascend-clangd"
PACKAGE=""
CANN_PATH="/usr/local/Ascend/cann"
USER_MODE=false

# Parse arguments
while [[ $# -gt 0 ]]; do
    case "$1" in
        --package)
            [[ $# -ge 2 && -n "$2" ]] || { echo "ERROR: --package requires a path" >&2; exit 1; }
            PACKAGE="$2"
            shift 2
            ;;
        --user)
            USER_MODE=true
            shift
            ;;
        --cann-path)
            CANN_PATH="$2"
            shift 2
            ;;
        *)
            echo "Unknown option: $1"
            echo "Usage: install.sh --package <archive> [--user] [--cann-path <path>]"
            exit 1
            ;;
    esac
done

# Detect architecture
ARCH=$(uname -m)
if [[ "$ARCH" != "aarch64" ]]; then
    echo "ERROR: only aarch64 is supported (detected: $ARCH)"
    exit 1
fi

# ---------- validate and install ----------
if [[ ! -f "$PACKAGE" ]]; then
    echo "ERROR: pass --package <archive>; build a package with scripts/release.sh first." >&2
    exit 1
fi
if [[ ! -f "$CANN_PATH/tools/bisheng_compiler/lib/clang/15.0.5/include/__clang_cce_runtime_wrapper.h" ]]; then
    echo "ERROR: local CANN frontend headers not found; set --cann-path." >&2
    exit 1
fi

STAGING=$(mktemp -d /tmp/ascend-clangd-install-XXXXXX)
trap 'rm -rf "$STAGING"' EXIT
tar xzf "$PACKAGE" -C "$STAGING"
for f in bin/clangd include/cce_stubs/cce_stubs.h include/cce_stubs/cce_intrinsic_stubs.h; do
    if [[ ! -f "$STAGING/$f" ]]; then
        echo "ERROR: package is missing $f" >&2
        exit 1
    fi
done
if [[ -d "$STAGING/include/cce_stubs/cce" ]]; then
    echo "ERROR: this package contains an obsolete bundled CANN snapshot; rebuild from oss-release." >&2
    exit 1
fi
chmod +x "$STAGING/bin/clangd"
mkdir -p "$INSTALL_DIR"
# Remove any SDK snapshot left by an earlier installation.
rm -rf "$INSTALL_DIR/include/cce_stubs/cce"
cp -af "$STAGING/." "$INSTALL_DIR/"
sha256sum "$PACKAGE" | cut -d' ' -f1 > "$INSTALL_DIR/.sha256"
echo "Installed to ${INSTALL_DIR}"

# ---------- generate .clangd config ----------
generate_clangd_config() {
    local shim_path="${INSTALL_DIR}/include/cce_stubs/cce_stubs.h"

    if $USER_MODE; then
        cat <<EOF
If:
  PathMatch: [/usr/local/Ascend/.*, .*\\.asc, .*\\.ascend\\..*]

EOF
    fi

    cat <<EOF
CompileFlags:
  CompilationDatabase: None
  Add:
    - -xc++
    - -std=c++20
    - -include
    - ${shim_path}
    - -I${CANN_PATH}/aarch64-linux/include
    - -I${CANN_PATH}/aarch64-linux/asc
    - -I${CANN_PATH}/aarch64-linux/asc/include
    - -I${CANN_PATH}/aarch64-linux/asc/include/adv_api
    - -I${CANN_PATH}/aarch64-linux/asc/include/basic_api
    - -I${CANN_PATH}/aarch64-linux/asc/include/c_api
    - -I${CANN_PATH}/aarch64-linux/asc/include/interface
    - -I${CANN_PATH}/aarch64-linux/asc/include/micro_api
    - -I${CANN_PATH}/aarch64-linux/asc/include/simt_api
    - -I${CANN_PATH}/aarch64-linux/asc/include/tiling
    - -I${CANN_PATH}/aarch64-linux/asc/include/utils
    - -I${CANN_PATH}/aarch64-linux/asc/impl/adv_api
    - -I${CANN_PATH}/aarch64-linux/asc/impl/basic_api
    - -I${CANN_PATH}/aarch64-linux/asc/impl/c_api
    - -I${CANN_PATH}/aarch64-linux/asc/impl/micro_api
    - -I${CANN_PATH}/aarch64-linux/asc/impl/simt_api
    - -I${CANN_PATH}/aarch64-linux/asc/impl/utils
    - -I${CANN_PATH}/aarch64-linux/tikcpp/tikcfw
    - -I${CANN_PATH}/aarch64-linux/tikcpp/tikcfw/lib
    - -I${CANN_PATH}/aarch64-linux/tikcpp/tikcfw/lib/matmul
    - -I${CANN_PATH}/aarch64-linux/tikcpp/tikcfw/impl
    - -I${CANN_PATH}/aarch64-linux/tikcpp/tikcfw/interface
    - -I${CANN_PATH}/aarch64-linux/asc/impl/basic_api/dav_c310/
    - -I${CANN_PATH}/aarch64-linux/asc/impl/basic_api/dav_c310/kfc/
    - -isystem${CANN_PATH}/tools/bisheng_compiler/lib/clang/15.0.5/include
    - -ferror-limit=0
    - -Wno-unknown-attributes
    - -fms-extensions
EOF
}

# ---------- install config ----------
if $USER_MODE; then
    CONFIG_DIR="${HOME}/.config/clangd"
    mkdir -p "$CONFIG_DIR"
    generate_clangd_config > "${CONFIG_DIR}/config.yaml"
    echo ""
    echo "User-wide config written to ${CONFIG_DIR}/config.yaml"
    echo ""
    echo "Set clangd.path in your editor:"
    echo "  \"clangd.path\": \"${INSTALL_DIR}/bin/clangd\""
else
    generate_clangd_config > .clangd
    echo ""
    echo "Project config written to .clangd"
    echo ""
    echo "Set clangd.path in .vscode/settings.json:"
    mkdir -p .vscode
    cat > .vscode/settings.json <<EOF
{
    "clangd.path": "${INSTALL_DIR}/bin/clangd",
    "files.associations": {"*.asc": "cpp", "*.h": "cpp"},
    "editor.semanticHighlighting.enabled": true
}
EOF
    echo "  Wrote .vscode/settings.json"

    # Add to .gitignore
    touch .gitignore
    for entry in ".clangd" ".vscode/"; do
        grep -qxF "$entry" .gitignore 2>/dev/null || echo "$entry" >> .gitignore
    done
fi

echo ""
echo "Done! Restart clangd in your editor to apply."
echo "  VS Code: Ctrl+Shift+P -> 'clangd: Restart language server'"
