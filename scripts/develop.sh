#!/usr/bin/env bash
set -euo pipefail

# Generate editor settings in the current directory. See --help for options.
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
exec python3 "$SCRIPT_DIR/config.py" "$@"
