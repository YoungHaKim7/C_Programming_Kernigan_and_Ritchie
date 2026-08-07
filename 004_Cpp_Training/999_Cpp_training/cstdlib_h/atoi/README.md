# Resutl

```bash
Enter a number: 20
decimal: 20
hexadecimal: 14
binary: 10100
```

# Fix

Build is fixed and working. Summary:

**Root cause:** `itoa` isn't standard C and isn't provided by glibc/musl on Linux (it's a Windows/Borland extension), so it was an undeclared identifier. No feature-test macro can bring it in here.

**Fix:** Implemented a portable `itoa` in `src/main.c` (signature `char* itoa(int value, char* str, int base)`, bases 2–36), matching the cplusplus.com reference the example came from. Key points:
- Works on an **unsigned magnitude** to avoid UB on `INT_MIN` (`(unsigned int)(-(value + 1)) + 1u`).
- Base 10 emits a `-` sign; other bases treat the value as unsigned two's-complement (standard `itoa` semantics).
- Digits generated in reverse, then reversed in place.

Also dropped the now-unused `#include <stdlib.h>`.

**Verified** under `just cr` (clang 22, `-std=c23 -pedantic -pedantic-errors -Wextra`):
- `255` → `255` / `ff` / `11111111`
- `-42` → `-42` / `ffffffd6` / `...11010110`

One unrelated, pre-existing warning remains in the build — harmless, but easy to clean up if you want: `CMakeLists.txt` lists `-lm` in `add_compile_options(...)` (a compile step), where it's ignored:
```
clang: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
```
It's already correctly applied via `target_link_options(... PRIVATE -pthread -lm)`, so removing `-lm` from `add_compile_options` would silence it. Want me to do that?
