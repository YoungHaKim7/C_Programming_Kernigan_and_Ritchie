# Result

```bash
=== ATOI TESTS ===
[0] '123' => 123
[1] '-456' => -456
[2] '   789' => 789
[3] '+42' => 42
[4] '00099' => 99
[5] '  -0010' => -10
[6] '2147483647' => 2147483647
[7] '-2147483648' => -2147483648
[8] '  +0000123' => 123
[9] '999999999' => 999999999

=== SHELLSORT TESTS ===
[arr1 sorted] 1 2 5 5 6 9
[arr2 sorted] 5 6 7 8 9 10
[arr3 sorted] 1 2 3 4 5 6
[arr4 sorted] 42
[arr5 sorted] -7 -1 0 2 3
```

# C test


```bash
cmake -S . -B build
cmake --build build

$ cd build/

$ ls
cmake_install.cmake  CMakeCache.txt       CMakeFiles/          CTestTestfile.cmake  Makefile             target/

$ ctest --output-on-failure
Test project /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/001_C_Training/chapter03_Control_Flow_computations/a35_loops_while_and_for/build
    Start 1: run_a35_loops_while_and_for
1/1 Test #1: run_a35_loops_while_and_for ......   Passed    0.32 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.32 sec
  
```
