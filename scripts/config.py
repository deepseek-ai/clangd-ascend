#!/usr/bin/env python3
"""Shared compiler flags and editor configuration for the CCE test workspace."""

import argparse
import json
from pathlib import Path

PROJECT_DIR = Path(__file__).resolve().parent.parent
DEFAULT_CLANGD = PROJECT_DIR / "build/bin/clangd"
DEFAULT_CANN = Path("/usr/local/Ascend/cann")


def compile_flags(cann_path=DEFAULT_CANN, *, no_shim=False):
    cann = Path(cann_path).resolve()
    stubs = PROJECT_DIR / "include/cce_stubs"
    flags = ["-xc++", "-std=c++20"]
    if not no_shim:
        flags += ["-include", str(stubs / "cce_stubs.h")]
    platform = cann / "aarch64-linux"
    flags += [f"-I{platform / 'include'}", f"-I{platform / 'asc'}"]
    for base in ("asc/include", "asc/impl"):
        flags.append(f"-I{platform / base}")
        for subdir in ("adv_api", "basic_api", "c_api", "interface", "micro_api",
                       "simt_api", "tiling", "utils"):
            flags.append(f"-I{platform / base / subdir}")
    for subdir in ("", "lib", "lib/matmul", "impl", "interface"):
        flags.append(f"-I{platform / 'tikcpp/tikcfw' / subdir}")
    for subdir in ("", "kfc"):
        flags.append(f"-I{platform / 'asc/impl/basic_api/dav_c310' / subdir}")
    flags += [f"-isystem{cann / 'tools/bisheng_compiler/lib/clang/15.0.5/include'}",
              "-ferror-limit=0", "-Wno-unknown-attributes", "-fms-extensions"]
    return flags


def add_arguments(parser):
    parser.add_argument("--cann-path", type=Path, default=DEFAULT_CANN)
    parser.add_argument("--clangd", type=Path, default=DEFAULT_CLANGD)
    parser.add_argument("--no-shim", action="store_true", help="Do not force-include cce_stubs.h")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    add_arguments(parser)
    args = parser.parse_args()
    flags = compile_flags(args.cann_path, no_shim=args.no_shim)
    Path(".clangd").write_text("CompileFlags:\n  CompilationDatabase: None\n  Add:\n" +
                               "".join(f"    - {json.dumps(flag)}\n" for flag in flags))
    settings_path = Path(".vscode/settings.json")
    settings_path.parent.mkdir(exist_ok=True)
    settings = json.loads(settings_path.read_text()) if settings_path.exists() else {}
    settings["clangd.path"] = str(args.clangd.resolve())
    settings.setdefault("files.associations", {}).update({"*.asc": "cpp", "*.h": "cpp"})
    settings["editor.semanticHighlighting.enabled"] = True
    settings_path.write_text(json.dumps(settings, indent=4) + "\n")
    print(f"Generated .clangd and .vscode/settings.json in {Path.cwd()}")


if __name__ == "__main__":
    main()
