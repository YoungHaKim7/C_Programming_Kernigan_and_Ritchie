# Result

- ctest

```bash

$ just ctest

rm -rf build
mkdir -p build
cmake -D CMAKE_C_COMPILER=/opt/homebrew/opt/gcc@15/bin/gcc-15 -S . -B build
-- The C compiler identification is GNU 15.1.0
-- Checking whether C compiler has -isysroot
-- Checking whether C compiler has -isysroot - yes
-- Checking whether C compiler supports OSX deployment target flag
-- Checking whether C compiler supports OSX deployment target flag - yes
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /opt/homebrew/opt/gcc@15/bin/gcc-15 - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done (0.8s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/001_C_Training/chapter05/a53_pointers_and_arrays/build
cmake --build build
[ 25%] Building C object CMakeFiles/a53_pointers_and_arrays.dir/src/main.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[ 50%] Linking C executable target/a53_pointers_and_arrays
[ 50%] Built target a53_pointers_and_arrays
[ 75%] Building C object CMakeFiles/test_pointers_arrays.dir/tests/test_pointers_arrays.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[100%] Linking C executable target/test_pointers_arrays
[100%] Built target test_pointers_arrays
ctest --test-dir ./build
Test project /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/001_C_Training/chapter05/a53_pointers_and_arrays/build
    Start 1: pointers_arrays_test
1/1 Test #1: pointers_arrays_test .............   Passed    0.38 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.38 sec

```


- `just cr`


```bash
$ just cr
just fm
fd -e c   -e h   -e cpp   -e hpp   -e cc   -e cxx -x /opt/homebrew/opt/llvm/bin/clang-format -style=file -i {} \;
rm -rf build
mkdir -p build
export CC=/opt/homebrew/opt/gcc@15/bin/gcc-15
cmake -D CMAKE_C_COMPILER=/opt/homebrew/opt/gcc@15/bin/gcc-15 -G Ninja .
-- The C compiler identification is GNU 15.1.0
-- Checking whether C compiler has -isysroot
-- Checking whether C compiler has -isysroot - yes
-- Checking whether C compiler supports OSX deployment target flag
-- Checking whether C compiler supports OSX deployment target flag - yes
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /opt/homebrew/opt/gcc@15/bin/gcc-15 - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done (0.7s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/001_C_Training/chapter05/a53_pointers_and_arrays
ninja
[1/4] Building C object CMakeFiles/a53_pointers_and_arrays.dir/src/main.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[2/4] Building C object CMakeFiles/test_pointers_arrays.dir/tests/test_pointers_arrays.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[4/4] Linking C executable target/a53_pointers_and_arrays
mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
./build/./target/a53_pointers_and_arrays
=== Pointers and Arrays Examples ===

1. Basic array and pointer assignment:
   a[0] = 0, *pa = 0
   Address of a[0]: 0x16d0664d0, pa: 0x16d0664d0

2. Pointer arithmetic:
   *(pa+1) = 1 (should be a[1] = 1)
   *(pa+3) = 3 (should be a[3] = 3)
   pa+2 points to address: 0x16d0664d8
   &a[2] is at address: 0x16d0664d8

3. Array indexing vs pointer arithmetic:
   a[0] = 0, *(a+0) = 0, *(pa+0) = 0
   a[1] = 1, *(a+1) = 1, *(pa+1) = 1
   a[2] = 2, *(a+2) = 2, *(pa+2) = 2
   a[3] = 3, *(a+3) = 3, *(pa+3) = 3
   a[4] = 4, *(a+4) = 4, *(pa+4) = 4

4. Address equivalence:
   &a[0] = 0x16d0664d0, a+0 = 0x16d0664d0
   &a[1] = 0x16d0664d4, a+1 = 0x16d0664d4
   &a[2] = 0x16d0664d8, a+2 = 0x16d0664d8

5. Pointer with array notation:
   pa[0] = 0, *(pa+0) = 0
   pa[1] = 1, *(pa+1) = 1
   pa[2] = 2, *(pa+2) = 2
   pa[3] = 3, *(pa+3) = 3
   pa[4] = 4, *(pa+4) = 4

6. strlen function examples:
   strlen_custom("hello") = 5
   strlen_custom("world") = 5
   strlen_custom("C programming") = 13
   strlen_custom("hello, world") = 12

7. Array vs pointer parameters:
   Using array notation: arr[0] = 10 arr[1] = 20 arr[2] = 30 arr[3] = 40 arr[4] = 50
   Using pointer notation: *(arr+0) = 10 *(arr+1) = 20 *(arr+2) = 30 *(arr+3) = 40 *(arr+4) = 50

8. Passing subarrays to functions:
   Full array: Processing subarray of size 10: 1 2 3 4 5 6 7 8 9 10
   Subarray starting at index 2: Processing subarray of size 8: 3 4 5 6 7 8 9 10
   Subarray starting at index 5: Processing subarray of size 5: 6 7 8 9 10

9. Pointer manipulation:
   Initial: *ptr = 100
   After ptr++: *ptr = 200
   After another ptr++: *ptr = 300
   After ptr--: *ptr = 200

10. Array name as address:
    Array name 'message' = 0x16d0663f8
    &message[0] = 0x16d0663f8
    message[0] = 'P'
    *message = 'P'
    msg_ptr = message, msg_ptr[1] = 'o'
 The build now completes successfully without any errors.
```
