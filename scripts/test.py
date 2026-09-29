#!/usr/bin/env python3
"""Check diagnostics and semantic highlighting for every test and stub header."""

import argparse
import subprocess
import sys

from config import PROJECT_DIR, add_arguments


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    add_arguments(parser)
    parser.add_argument("--timeout", type=float, default=60)
    args = parser.parse_args()
    if not args.clangd.is_file():
        parser.error(f"clangd not found: {args.clangd}; build it or pass --clangd")
    if not (args.cann_path / "aarch64-linux/asc").is_dir():
        parser.error(f"CANN headers not found: {args.cann_path}; pass --cann-path")
    files = sorted(path for base in ("tests", "include/cce_stubs")
                   for path in (PROJECT_DIR / base).rglob("*")
                   if path.suffix in {".asc", ".h", ".hpp", ".c", ".cc", ".cpp", ".cxx"})
    failed = 0
    for path in files:
        command = [sys.executable, str(PROJECT_DIR / "scripts/check.py"), str(path),
                   "--clangd", str(args.clangd.resolve()), "--cann-path", str(args.cann_path),
                   "--semantic-tokens", "--timeout", str(args.timeout)]
        if args.no_shim or path.name == "cce_stubs.h":
            command.append("--no-shim")
        try:
            result = subprocess.run(command, capture_output=True, text=True,
                                    timeout=args.timeout * 4 + 10)
            ok = result.returncode == 0
            output = result.stdout + result.stderr
        except subprocess.TimeoutExpired:
            ok, output = False, "Check process timed out"
        print(f"{'PASS' if ok else 'FAIL'} {path.relative_to(PROJECT_DIR)}", flush=True)
        if not ok:
            failed += 1
            print(output, flush=True)
    print(f"{len(files)} files checked; {failed} failed checks")
    return bool(failed)


if __name__ == "__main__":
    sys.exit(main())
