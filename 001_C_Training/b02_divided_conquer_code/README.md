# Result

```bash
Type some text (Ctrl+D to end):
short
this is the longest line entered so far
tiny
this is the longest line entered so far

Done!
```


#  Excellent! The program is working correctly.

- Summary

  I've successfully fixed the multiple definition errors in your C code. The issues were:
  1. Direct inclusion of `.c` files: In main.c, you were using #include "getline02.c" and #include "copy.c" which caused the functions to be
     defined multiple times during compilation.
  2. Duplicate header declarations: The get_copy.h file had duplicate function declarations that were already present in common.h.


- Changes Made:

  1. Fixed `src/main.c`: Removed the direct inclusion of .c files and kept only the proper header include (#include "headers/common.h")
  2. Cleaned up headers: Removed the redundant get_copy.h file since all necessary declarations are already in common.h

  The program now compiles successfully and works as expected - it reads input lines and prints the longest one. The build system correctly
  links the separate object files without any multiple definition errors.
