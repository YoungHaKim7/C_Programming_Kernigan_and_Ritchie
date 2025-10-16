# Result


```bash
Press Ctrl+D to exit.

Calculator Console Application
Please enter the operation to perform. Format: a+b | a-b | a*b | a/b
3+5
Result of 3+5 is: 8
Thank you for using the calculator. Goodbye!
```


# ● Perfect! The build now succeeds. I've fixed the code by:

- 1. Removed the fmt/core.h and fmt/format.h includes that were causing the compilation error
- 2. Added `#include <cstdio>` for `std::scanf`
- 3. Replaced `fmt::scan` with `std::scanf`
- 4. Fixed the syntax error in the `std::println` call (missing comma between y and result)
- 5. Used only C++26 standard library features (`std::print`, `std::println`) without iostream
  - The calculator should now compile and run correctly with GCC 15 and C++26.
