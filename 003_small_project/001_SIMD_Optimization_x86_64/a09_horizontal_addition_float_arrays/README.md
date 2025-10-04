# Result(`-msse3` 옵션 추가해야함)

```bash
/opt/gcc-15/bin/gcc -std=c23 -msse3 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a09_horizontal_addition_float_arrays ./src/main.c
./target/a09_horizontal_addition_float_arrays
3.000000 7.000000 3.000000 7.000000

```


# fix code

```bash
I need to examine the code to understand the issue and fix it. The error indicates a target specific
  option mismatch with the _mm_hadd_ps intrinsic function.

  ⬢ Read src/main.c

  The issue is that _mm_hadd_ps is part of the SSE3 instruction set, but the compiler isn't being told to
  enable SSE3 support. The pmmintrin.h header provides SSE3 intrinsics, but we need to add the appropriate
   compiler flags to enable SSE3 instructions.
  Let me check if there's a Makefile or build script to understand the current compilation setup:

  ⬢ Listed, read 1 directory, 1 file
    Listed .
    Read justfile

  Now I can see the issue. The problem is that the code is using SSE3 intrinsics (_mm_hadd_ps) but the
  compiler flags don't include the necessary SSE3 target options. The _mm_hadd_ps function requires SSE3
  support, which needs to be explicitly enabled.
  Let me create a todo list to track the fix:

  ⬢ To-do Working on 2 to-dos
    ☐ Add SSE3 compiler flags to enable _mm_hadd_ps intrinsic
    ☐ Test the fixed compilation


```
