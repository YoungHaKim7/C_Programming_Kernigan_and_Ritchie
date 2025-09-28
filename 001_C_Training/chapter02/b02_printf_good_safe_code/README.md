# Result

```bash
/opt/homebrew/opt/llvm/bin/clang -g -fsanitize=address -fno-omit-frame-pointer -c ./src/main.c
/opt/homebrew/opt/llvm/bin/clang -g -fsanitize=address *.o
mv a.out *.o ./target
./target/a.out

a.out(6682,0x20ba22140) malloc: nano zone abandoned due to inability to reserve vm space.
TEST


# message 없애기(macOS에만 그런듯)
$ export MallocNanoZone=0

$ ./target/a.out
TEST
```


# macOS하니 나오는 메세지 분석
- What’s happening
  - On macOS, malloc uses a “nano zone” allocator for small allocations (<= 256 bytes).
  - This allocator tries to reserve a block of virtual memory at startup.
  - If something interferes with this reservation (e.g., running under AddressSanitizer, custom allocators, Rosetta, or a restricted environment), malloc falls back to the default “scalable” allocator.
  - That fallback is announced with this warning.
  - So the warning isn’t a bug in your code. Your code is correct (allocates 5 bytes, stores "TEST\0" safely, frees memory).
