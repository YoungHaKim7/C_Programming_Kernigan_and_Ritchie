# Result

```bash
/opt/homebrew/opt/llvm/bin/clang -g -fsanitize=address -fno-omit-frame-pointer -c ./src/main.c
/opt/homebrew/opt/llvm/bin/clang -g -fsanitize=address *.o
mv a.out *.o ./target
./target/a.out
a.out(4486,0x20ba22140) malloc: nano zone abandoned due to inability to reserve vm space.
=================================================================
==4486==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x6020000000b4 at pc 0x0001027bea60 bp 0x00016dd36560 sp 0x00016dd35cf0
READ of size 5 at 0x6020000000b4 thread T0
    #0 0x0001027bea5c in printf_common(void*, char const*, char*)+0x890 (libclang_rt.asan_osx_dynamic.dylib:arm64+0x22a5c)
    #1 0x0001027bf840 in printf+0x60 (libclang_rt.asan_osx_dynamic.dylib:arm64+0x23840)
    #2 0x0001020c895c in main+0x1ac (a.out:arm64+0x10000095c)
    #3 0x00019d726b94  (<unknown module>)

0x6020000000b4 is located 0 bytes after 4-byte region [0x6020000000b0,0x6020000000b4)
allocated by thread T0 here:
    #0 0x0001027ef478 in malloc+0x70 (libclang_rt.asan_osx_dynamic.dylib:arm64+0x53478)
    #1 0x0001020c87d4 in main+0x24 (a.out:arm64+0x1000007d4)
    #2 0x00019d726b94  (<unknown module>)

SUMMARY: AddressSanitizer: heap-buffer-overflow (a.out:arm64+0x10000095c) in main+0x1ac
Shadow bytes around the buggy address:
  0x601ffffffe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x601ffffffe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x601fffffff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x601fffffff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x602000000000: fa fa fd fa fa fa fd fd fa fa fd fd fa fa 00 06
=>0x602000000080: fa fa 00 00 fa fa[04]fa fa fa fa fa fa fa fa fa
  0x602000000100: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x602000000180: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x602000000200: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x602000000280: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x602000000300: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
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
==4486==ABORTING
```
