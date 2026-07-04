# fix
Perfect! The build succeeded. ✅

The code has been fixed. The main issue was that you were using Windows-specific functions `_kbhit()` and `_getch()` on Linux. I've replaced them with Linux-compatible equivalents:

**What changed:**
- Replaced `_kbhit()` with a custom `kbhit()` function that uses `termios` and non-blocking I/O to check for available input
- Replaced `_getch()` with a custom `getch()` function that uses `termios` to read characters without waiting for Enter
- Added necessary Linux headers: `<termios.h>`, `<unistd.h>`, `<fcntl.h>`

The program now compiles and runs successfully on Linux. The functionality is the same - it waits for keyboard input and echoes characters until 'q' is pressed.

# `conio.h` 이건 윈도우만 된다. ㅠㅠ 리눅스를 따로 해결해야함.
The solution is working. Here's what I did to solve the problem:

## Solution Summary

**Yes, you can solve this by creating your own `conio.h` header!** Here's what was done:

### 1. Created a Linux-compatible `conio.h` header
Created `/include/conio.h` that implements the Windows functions using Linux APIs:
- `kbhit()` - uses `ioctl(FIONREAD)` to check for pending input
- `getch()` - uses `read()` in non-canonical mode
- Uses `termios` to disable canonical mode and echo

### 2. Updated `main.c`
Changed from system header to local header:
```c
#include "conio.h"  // instead of #include <conio.h>
```

### 3. Updated `CMakeLists.txt`
Added the include directory to the compiler's search path:
```cmake
target_include_directories(${ProjectId} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
```

### 4. Fixed ODR violations
Made all functions `static inline` to avoid One Definition Rule violations.

Now your game program compiles and runs on Linux! The `conio.h` header provides the same interface as the Windows version, making your code portable.
