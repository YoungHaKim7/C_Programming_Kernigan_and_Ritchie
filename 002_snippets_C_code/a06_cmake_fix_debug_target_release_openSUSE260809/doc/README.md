Fixed. `just rd` now compiles a real debug executable and runs it:

```
sum 1..5 = 15
values[0] = 10
...
values[4] = 50
```

**Root cause:** `ldflags_clang_debug` was `--analyze -std=c23 -Xanalyzer -analyzer-output=text`. The `--analyze` flag runs Clang's static analyzer, which emits diagnostics but **produces no binary** — so the next line, `./{{target}}`, failed with `No such file or directory` (exit 127).

**Fix:** Replaced `ldflags_clang_debug` with a genuine debug compile (`-O0 -g -ggdb`, mirroring `ldflags_common` but unoptimized with debug info), and preserved the original analyze flags as a separate `ldflags_clang_analyze` variable in case you want a dedicated static-analysis recipe later (e.g. a `analyze:` recipe).
