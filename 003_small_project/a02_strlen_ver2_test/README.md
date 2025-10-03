# Result

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
-- Configuring done (0.7s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/003_small_project/a02_strlen_ver2_test/build
cmake --build build
[ 16%] Building C object CMakeFiles/a02_strlen_ver2_test.dir/src/main.c.o
[ 33%] Building C object CMakeFiles/a02_strlen_ver2_test.dir/src/strlen_impl.c.o
[ 50%] Linking C executable target/a02_strlen_ver2_test
[ 50%] Built target a02_strlen_ver2_test
[ 66%] Building C object CMakeFiles/test_strlen.dir/src/test_strlen.c.o
[ 83%] Building C object CMakeFiles/test_strlen.dir/src/strlen_impl.c.o
[100%] Linking C executable target/test_strlen
[100%] Built target test_strlen
ctest --test-dir ./build
Test project /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/003_small_project/a02_strlen_ver2_test/build
    Start 1: run_a02_strlen_ver2_test
1/2 Test #1: run_a02_strlen_ver2_test .........***Failed  Required regular expression not found. Regex=[🎉 All implementations produce identical results!
]  0.53 sec
    Start 2: run_test_strlen
2/2 Test #2: run_test_strlen ..................***Failed  Required regular expression not found. Regex=[🎉 All tests passed!
]  0.32 sec

0% tests passed, 2 tests failed out of 2

Total Test time (real) =   0.85 sec

The following tests FAILED:
	  1 - run_a02_strlen_ver2_test (Failed)
	  2 - run_test_strlen (Failed)
Errors while running CTest
Output from these tests are in: /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/003_small_project/a02_strlen_ver2_test/build/Testing/Temporary/LastTest.log
Use "--rerun-failed --output-on-failure" to re-run the failed cases verbosely.
```
