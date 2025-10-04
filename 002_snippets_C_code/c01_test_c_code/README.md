# link

- [justfile setting복사해서 쓰기](#justfile)
  - [justfile통합ver(LinuxOS vs macOS인지 if문으로 처리)](#justfile통합verlinuxos-vs-macos인지-if문으로-처리)

<hr />

# cmake (ctest 문서)[|🔝|](#link)
- https://cmake.org/cmake/help/latest/manual/ctest.1.html

# Test C code[|🔝|](#link)

- `just ctest`

```bash
$ just ctest

cmake -D CMAKE_C_COMPILER=/opt/gcc-15/bin/gcc -S . -B build
-- The C compiler identification is GNU 15.1.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /opt/gcc-15/bin/gcc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done (8.2s)
-- Generating done (0.0s)
-- Build files have been written to: /home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/002_snippets_C_code/c01_test_c_code/build
cmake --build build
[ 50%] Building C object CMakeFiles/c01_test_c_code.dir/src/main.c.o
[100%] Linking C executable target/c01_test_c_code
[100%] Built target c01_test_c_code
ctest --test-dir ./build
Test project /home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/002_snippets_C_code/c01_test_c_code/build
    Start 1: run_c01_test_c_code
1/1 Test #1: run_c01_test_c_code ..............   Passed    0.68 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.68 sec

```

- `ctest`

```bash
cmake -S . -B build
cmake --build build
cd build
ctest --output-on-failure

# result

$ ctest --output-on-failure
Test project /Users/gy/C_Programming_Kernigan_and_Ritchie/001_C_Training/d01_test_c_code/build
    Start 1: run_d01_test_c_code
1/1 Test #1: run_d01_test_c_code ..............   Passed    0.35 sec

100% tests passed, 0 tests failed out of 1    
```

# Result[|🔝|](#link)

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
