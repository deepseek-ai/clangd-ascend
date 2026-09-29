#!/usr/bin/env python3
"""
Check a source file using the locally-built clangd via LSP.

Launches clangd, opens the given file, collects diagnostics, and prints
errors/warnings with file path, line number, column, severity, and message.

Usage:
    python3 scripts/check.py <file>
    python3 scripts/check.py tests/bf16_gemm.asc
    python3 scripts/check.py --clangd /path/to/clangd <file>
"""

import json
import os
import subprocess
import sys
import tempfile
import threading
from pathlib import Path

from config import DEFAULT_CLANGD, PROJECT_DIR, add_arguments, compile_flags

SEVERITY_MAP = {
    1: "error",
    2: "warning",
    3: "info",
    4: "hint",
}


class LSPClient:
    """Minimal LSP client that communicates with clangd over stdin/stdout."""

    def __init__(self, clangd_path: str, root_dir: str, *, file_path=None, flags=None):
        self._database = None
        command = [clangd_path, "--log=error", "--background-index=0"]
        if flags is not None:
            self._database = tempfile.TemporaryDirectory(prefix="clangd-ascend-check-")
            Path(self._database.name, "compile_commands.json").write_text(json.dumps([{
                "directory": root_dir, "file": str(file_path),
                "arguments": ["clang++", *flags, str(file_path)],
            }]))
            command += [f"--compile-commands-dir={self._database.name}", "--enable-config=0"]
        self.process = subprocess.Popen(
            command,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
        )
        self.root_dir = root_dir
        self._req_id = 0
        self._diagnostics: list[dict] = []
        self._diagnostics_received = threading.Event()
        self._responses: dict[int, dict] = {}
        self._response_events: dict[int, threading.Event] = {}
        self._lock = threading.Lock()
        self._reader_thread = threading.Thread(target=self._read_loop, daemon=True)
        self._reader_thread.start()

    def _send(self, msg: dict):
        body = json.dumps(msg).encode("utf-8")
        header = f"Content-Length: {len(body)}\r\n\r\n".encode("ascii")
        self.process.stdin.write(header + body)
        self.process.stdin.flush()

    def _read_message(self) -> dict | None:
        """Read one LSP message from stdout."""
        headers = {}
        while True:
            line = self.process.stdout.readline()
            if not line:
                return None
            line = line.decode("ascii").strip()
            if line == "":
                break
            if ":" in line:
                key, val = line.split(":", 1)
                headers[key.strip()] = val.strip()

        content_length = int(headers.get("Content-Length", 0))
        if content_length == 0:
            return None

        body = self.process.stdout.read(content_length)
        return json.loads(body.decode("utf-8"))

    def _read_loop(self):
        """Background thread reading all messages from clangd."""
        while True:
            msg = self._read_message()
            if msg is None:
                break

            if "id" in msg and "method" not in msg:
                # Response to a request
                req_id = msg["id"]
                with self._lock:
                    self._responses[req_id] = msg
                    event = self._response_events.get(req_id)
                if event:
                    event.set()
            elif msg.get("method") == "textDocument/publishDiagnostics":
                # Notification with diagnostics
                self._diagnostics.append(msg["params"])
                self._diagnostics_received.set()

    def request(self, method: str, params: dict) -> dict:
        self._req_id += 1
        req_id = self._req_id
        event = threading.Event()
        with self._lock:
            self._response_events[req_id] = event

        msg = {"jsonrpc": "2.0", "id": req_id, "method": method, "params": params}
        self._send(msg)
        if not event.wait(timeout=getattr(self, "timeout", 60)):
            raise TimeoutError(f"Timed out waiting for {method}")

        with self._lock:
            self._response_events.pop(req_id, None)
            response = self._responses.pop(req_id)
        if "error" in response:
            raise RuntimeError(f"{method}: {response['error']}")
        return response

    def notify(self, method: str, params: dict):
        msg = {"jsonrpc": "2.0", "method": method, "params": params}
        self._send(msg)

    def initialize(self):
        root_uri = Path(self.root_dir).as_uri()
        result = self.request("initialize", {
            "processId": os.getpid(),
            "rootUri": root_uri,
            "capabilities": {
                "textDocument": {
                    "semanticTokens": {
                        "requests": {"full": True},
                        "tokenTypes": ["variable", "function", "type", "macro"],
                        "tokenModifiers": [],
                        "formats": ["relative"],
                    },
                    "publishDiagnostics": {
                        "relatedInformation": True,
                    }
                }
            },
        })
        self.notify("initialized", {})
        return result

    def open_file(self, file_path: str):
        uri = Path(file_path).resolve().as_uri()
        text = Path(file_path).read_text(encoding="utf-8", errors="replace")
        self.notify("textDocument/didOpen", {
            "textDocument": {
                "uri": uri,
                "languageId": "cpp",
                "version": 1,
                "text": text,
            }
        })

    def wait_for_diagnostics(self, timeout: float = 60.0, file_path: str = "") -> list[dict]:
        """Wait for clangd to finish processing the file and return diagnostics.

        Strategy: send a synchronous request (documentSymbol) which forces
        clangd to finish all pending work for the file first. By the time the
        response comes back, all publishDiagnostics notifications will have
        been sent.
        """
        if file_path:
            uri = Path(file_path).resolve().as_uri()
            # This blocks until clangd responds, ensuring file is fully parsed.
            self.request("textDocument/documentSymbol", {
                "textDocument": {"uri": uri}
            })
        else:
            self._diagnostics_received.wait(timeout=timeout)

        uri = Path(file_path).resolve().as_uri() if file_path else None
        matching = [d for d in self._diagnostics if uri is None or d["uri"] == uri]
        if not matching:
            raise RuntimeError("clangd did not publish diagnostics")
        return matching[-1:]

    def shutdown(self):
        self.request("shutdown", {})
        self.notify("exit", {})
        try:
            self.process.wait(timeout=5)
        finally:
            self.close()

    def close(self):
        if self.process.poll() is None:
            self.process.kill()
        self.process.wait()
        self.process.stdin.close()
        self.process.stdout.close()
        self._reader_thread.join(timeout=1)
        if self._database:
            self._database.cleanup()


def format_diagnostics(diagnostics_list: list[dict]) -> list[str]:
    """Format diagnostics into human-readable lines."""
    lines = []
    for params in diagnostics_list:
        uri = params.get("uri", "")
        # Convert file URI to path
        if uri.startswith("file://"):
            file_path = uri[len("file://"):]
        else:
            file_path = uri

        for diag in params.get("diagnostics", []):
            rng = diag.get("range", {})
            start = rng.get("start", {})
            line = start.get("line", 0) + 1  # LSP lines are 0-indexed
            col = start.get("character", 0) + 1
            severity = SEVERITY_MAP.get(diag.get("severity", 1), "unknown")
            message = diag.get("message", "")
            source = diag.get("source", "")

            prefix = f"{file_path}:{line}:{col}"
            severity_str = severity
            source_str = f" [{source}]" if source else ""
            lines.append(f"{prefix}: {severity_str}{source_str}: {message}")

            # Print related information if available
            for related in diag.get("relatedInformation", []):
                rel_loc = related.get("location", {})
                rel_uri = rel_loc.get("uri", "")
                if rel_uri.startswith("file://"):
                    rel_path = rel_uri[len("file://"):]
                else:
                    rel_path = rel_uri
                rel_range = rel_loc.get("range", {}).get("start", {})
                rel_line = rel_range.get("line", 0) + 1
                rel_col = rel_range.get("character", 0) + 1
                rel_msg = related.get("message", "")
                lines.append(f"  {rel_path}:{rel_line}:{rel_col}: note: {rel_msg}")

    return lines


def main():
    import argparse

    parser = argparse.ArgumentParser(
        description="Check a file for errors using the locally-built clangd"
    )
    parser.add_argument("file", help="Source file to check")
    add_arguments(parser)
    parser.add_argument(
        "--root",
        default=str(PROJECT_DIR),
        help=f"Project root directory (default: {PROJECT_DIR})",
    )
    parser.add_argument(
        "--timeout",
        type=float,
        default=60.0,
        help="Timeout in seconds to wait for diagnostics (default: 60)",
    )
    parser.add_argument("--semantic-tokens", action="store_true",
                        help="Require non-empty semantic highlighting tokens")
    args = parser.parse_args()

    # Validate inputs
    if not Path(args.clangd).is_file():
        print(f"Error: clangd not found at {args.clangd}", file=sys.stderr)
        print("Run scripts/build-clangd.sh first.", file=sys.stderr)
        sys.exit(1)

    file_path = Path(args.file).resolve()
    if not file_path.is_file():
        print(f"Error: file not found: {args.file}", file=sys.stderr)
        sys.exit(1)

    # Run clangd LSP check
    client = LSPClient(str(args.clangd), str(Path(args.root).resolve()),
                       file_path=file_path, flags=compile_flags(
                           args.cann_path, no_shim=args.no_shim))
    client.timeout = args.timeout
    try:
        client.initialize()
        client.open_file(str(file_path))
        diagnostics = client.wait_for_diagnostics(timeout=args.timeout, file_path=str(file_path))
        if args.semantic_tokens:
            result = client.request("textDocument/semanticTokens/full", {
                "textDocument": {"uri": file_path.as_uri()}
            }).get("result")
            if not result or not result.get("data") or len(result["data"]) % 5:
                raise RuntimeError("clangd returned no semantic highlighting tokens")
            print(f"{file_path}: {len(result['data']) // 5} semantic tokens")
        client.shutdown()
    except Exception as e:
        print(f"Error communicating with clangd: {e}", file=sys.stderr)
        client.close()
        sys.exit(1)

    # Format and print results
    lines = format_diagnostics(diagnostics)

    if not lines:
        print(f"{file_path}: no diagnostics")
        sys.exit(0)

    items = [diag for params in diagnostics for diag in params.get("diagnostics", [])]
    error_count = sum(diag.get("severity", 1) == 1 for diag in items)
    warning_count = sum(diag.get("severity") == 2 for diag in items)
    for line in lines:
        print(line)

    print(f"\n{error_count} error(s), {warning_count} warning(s)")
    sys.exit(1 if error_count > 0 else 0)


if __name__ == "__main__":
    main()
