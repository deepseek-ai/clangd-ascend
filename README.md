# clangd-ascend

clangd-ascend is a customized version of clangd for AscendC, providing code
completion, diagnostics, navigation, and other features for `.asc` files to aid
kernel development. It supports most AscendC builtin types, address spaces, and
kernel launch syntax. The headers in `include/cce_stubs/` provide declarations
for builtin functions.

clangd-ascend 是对 AscendC 定制的 clangd，能够为 `.asc` 文件提供代码补全、诊断、跳转等功能，为算子开发提供辅助。clangd-ascend 支持大部分 AscendC 的内建类型、地址空间和内核启动语法。`include/cce_stubs/` 中的头文件提供了内建函数的声明。

## Quick Start

Download LLVM and build clangd:

```bash
git clone https://github.com/deepseek-ai/clangd-ascend.git
cd clangd-ascend
./scripts/build-clangd.sh
./scripts/release.sh
```

Both modes install clangd and headers to `~/.ascend-clangd/`. CANN headers are
read from `/usr/local/Ascend/cann`; use `--cann-path` to change this.

```bash
# Local: configure the current project (.clangd and .vscode/settings.json).
./install.sh --package dist/ascend-clangd-aarch64.tar.gz

# User: configure matching Ascend files across projects (~/.config/clangd/config.yaml).
./install.sh --user --package dist/ascend-clangd-aarch64.tar.gz
```

The configuration files are overwritten. In user mode, set your editor's clangd
path to `~/.ascend-clangd/bin/clangd`.

In VS Code, press **Ctrl+Shift+P** and run **clangd: Restart language server**
after installation.

## License

Project code, including the editor stubs in `include/`, uses the [MIT License](LICENSE).
LLVM patches use [Apache-2.0 WITH LLVM-exception](patches/LICENSE), with the
full license text included in that file.
SDK headers are supplied by the user's local CANN installation under its
accompanying terms.
See [NOTICE](NOTICE) for component origins and redistribution notices.
