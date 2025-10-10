# Result

```bash
ptr : 0x7b99ca7c9020¶
```


<hr />

# free된 메모리에 Allocation한 문제의 코드

```c
// error code
int* ptr = malloc(sizeof(int));
printf("ptr : %p", &ptr);
free(ptr);
*ptr = 42;
return 0;
```


# Result


```bash
$ /usr/bin/clang-20 -g -fsanitize=address -fno-omit-frame-pointer -c ./src/main.c
$ /usr/bin/clang-20 -g -fsanitize=address *.o
$ mv a.out *.o ./target
$ ./target/a.out

=================================================================
==1466==ERROR: AddressSanitizer: heap-use-after-free on address 0x7c02a31e0010 at pc 0x7fe2a439f728 bp 0x7fffc5ecc350 sp 0x7fffc5ecc348
WRITE of size 4 at 0x7c02a31e0010 thread T0
    #0 0x7fe2a439f727 in main /home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/001_C_Training/c01_malloc_free/a01_malloc_free_simp
le/./src/main.c:17:10
    #1 0x7fe2a3f1a1c9 in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #2 0x7fe2a3f1a28a in __libc_start_main csu/../csu/libc-start.c:360:3
    #3 0x7fe2a42b7354 in _start (/home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/001_C_Training/c01_malloc_free/a01_malloc_free_s
imple/target/a.out+0x2c354) (BuildId: f3d4ce4384da1751bf84c9b9e90baeddc125c5de)

0x7c02a31e0010 is located 0 bytes inside of 4-byte region [0x7c02a31e0010,0x7c02a31e0014)
freed by thread T0 here:
    #0 0x7fe2a435abca in free build-llvm/tools/clang/stage2-bins/runtimes/runtimes-bins/compiler-rt/lib/asan/asan_malloc_linux.cpp:51:3
    #1 0x7fe2a439f6ee in main /home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/001_C_Training/c01_malloc_free/a01_malloc_free_simp
le/./src/main.c:16:5
    #2 0x7fe2a3f1a1c9 in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #3 0x7fe2a3f1a28a in __libc_start_main csu/../csu/libc-start.c:360:3
    #4 0x7fe2a42b7354 in _start (/home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/001_C_Training/c01_malloc_free/a01_malloc_free_s
imple/target/a.out+0x2c354) (BuildId: f3d4ce4384da1751bf84c9b9e90baeddc125c5de)

previously allocated by thread T0 here:
    #0 0x7fe2a435ae68 in malloc build-llvm/tools/clang/stage2-bins/runtimes/runtimes-bins/compiler-rt/lib/asan/asan_malloc_linux.cpp:67:3
    #1 0x7fe2a439f6c4 in main /home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/001_C_Training/c01_malloc_free/a01_malloc_free_simp
le/./src/main.c:14:16
    #2 0x7fe2a3f1a1c9 in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #3 0x7fe2a3f1a28a in __libc_start_main csu/../csu/libc-start.c:360:3
    #4 0x7fe2a42b7354 in _start (/home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/001_C_Training/c01_malloc_free/a01_malloc_free_s
imple/target/a.out+0x2c354) (BuildId: f3d4ce4384da1751bf84c9b9e90baeddc125c5de)

SUMMARY: AddressSanitizer: heap-use-after-free /home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/001_C_Training/c01_malloc_free/a01
_malloc_free_simple/./src/main.c:17:10 in main
Shadow bytes around the buggy address:
  0x7c02a31dfd80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7c02a31dfe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7c02a31dfe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7c02a31dff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7c02a31dff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x7c02a31e0000: fa fa[fd]fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x7c02a31e0080: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x7c02a31e0100: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x7c02a31e0180: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x7c02a31e0200: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x7c02a31e0280: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==1466==ABORTING
```
