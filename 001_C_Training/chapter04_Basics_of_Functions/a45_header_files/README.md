# justfile 여기서 copy해서 쓰면됨.
[c02_calculator_header_divided_conquer_code_test#justfile](/002_snippets_C_code/c02_calculator_header_divided_conquer_code_test#justfile)

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
-- Build files have been written to: /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/002_snippets_C_code/c02_calculator_header_divided_conquer_code_test/build
cmake --build build
[ 10%] Building C object CMakeFiles/c02_calculator_header_divided_conquer_code_test.dir/src/main.c.o
[ 20%] Building C object CMakeFiles/c02_calculator_header_divided_conquer_code_test.dir/src/getop.c.o
[ 30%] Building C object CMakeFiles/c02_calculator_header_divided_conquer_code_test.dir/src/getch.c.o
[ 40%] Building C object CMakeFiles/c02_calculator_header_divided_conquer_code_test.dir/src/stack.c.o
[ 50%] Linking C executable target/c02_calculator_header_divided_conquer_code_test
[ 50%] Built target c02_calculator_header_divided_conquer_code_test
[ 60%] Building C object CMakeFiles/test_runner.dir/test/test.c.o
[ 70%] Building C object CMakeFiles/test_runner.dir/src/getop.c.o
[ 80%] Building C object CMakeFiles/test_runner.dir/src/getch.c.o
[ 90%] Building C object CMakeFiles/test_runner.dir/src/stack.c.o
[100%] Linking C executable target/test_runner
[100%] Built target test_runner
ctest --test-dir ./build
Test project /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/002_snippets_C_code/c02_calculator_header_divided_conquer_code_test/build
    Start 1: calculator_tests
2 3 +
1/1 Test #1: calculator_tests .................   Passed    4.74 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   4.75 sec

…_code/c02_calculator_header_divided_conquer_code_test on  main via △ v4.1.1 took 6s
❯ just ctest
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
-- Build files have been written to: /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/002_snippets_C_code/c02_calculator_header_divided_conquer_code_test/build
cmake --build build
[ 10%] Building C object CMakeFiles/c02_calculator_header_divided_conquer_code_test.dir/src/main.c.o
[ 20%] Building C object CMakeFiles/c02_calculator_header_divided_conquer_code_test.dir/src/getop.c.o
[ 30%] Building C object CMakeFiles/c02_calculator_header_divided_conquer_code_test.dir/src/getch.c.o
[ 40%] Building C object CMakeFiles/c02_calculator_header_divided_conquer_code_test.dir/src/stack.c.o
[ 50%] Linking C executable target/c02_calculator_header_divided_conquer_code_test
[ 50%] Built target c02_calculator_header_divided_conquer_code_test
[ 60%] Building C object CMakeFiles/test_runner.dir/test/test.c.o
[ 70%] Building C object CMakeFiles/test_runner.dir/src/getop.c.o
[ 80%] Building C object CMakeFiles/test_runner.dir/src/getch.c.o
[ 90%] Building C object CMakeFiles/test_runner.dir/src/stack.c.o
[100%] Linking C executable target/test_runner
[100%] Built target test_runner
ctest --test-dir ./build
Test project /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/002_snippets_C_code/c02_calculator_header_divided_conquer_code_test/build
    Start 1: calculator_tests
2 3 +

1/1 Test #1: calculator_tests .................   Passed    5.30 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   5.30 sec

# ~~~~
# ~~~~

$ just cr
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
-- Build files have been written to: /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/002_snippets_C_code/c02_calculator_header_divided_conquer_code_test
ninja
[10/10] Linking C executable target/test_runner
mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
./build/./target/c02_calculator_header_divided_conquer_code_test
Type some text (Ctrl+D to end) 'ex) 2 3 +' :
2 3 +
	5
^D
Done!
```
