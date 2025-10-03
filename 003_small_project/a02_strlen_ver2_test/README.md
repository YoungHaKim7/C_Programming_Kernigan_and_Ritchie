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


# run_test.sh


```bash
./test_runner.sh
[INFO] Building project...
rm -rf build
mkdir -p build/target
gcc -Wall -Wextra -std=c23 -g -O2 -o build/target/a01_strlen_impl src/main.c src/strlen_impl.c -lm
gcc -Wall -Wextra -std=c23 -g -O2 -o build/target/test_strlen src/test_strlen.c src/strlen_impl.c -lm
[SUCCESS] Project built successfully using Makefile

[INFO] Running all tests...
[INFO] Running basic strlen comparison tests...
=== STRLEN IMPLEMENTATION COMPARISON ===

Test 1: ""
  strlen_simple    = 0
  strlen_glibc     = 0
  strlen_recursive = 0
  strlen_while     = 0
  strlen(builtin)  = 0
  ✅ All implementations match
--------------------------------------------------
Test 2: "a"
  strlen_simple    = 1
  strlen_glibc     = 1
  strlen_recursive = 1
  strlen_while     = 1
  strlen(builtin)  = 1
  ✅ All implementations match
--------------------------------------------------
Test 3: "Hello"
  strlen_simple    = 5
  strlen_glibc     = 8
  strlen_recursive = 5
  strlen_while     = 5
  strlen(builtin)  = 5
  ❌ Mismatch detected!
--------------------------------------------------
Test 4: "This is a test"
  strlen_simple    = 14
  strlen_glibc     = 16
  strlen_recursive = 14
  strlen_while     = 14
  strlen(builtin)  = 14
  ❌ Mismatch detected!
--------------------------------------------------
Test 5: "1234567890"
  strlen_simple    = 10
  strlen_glibc     = 10
  strlen_recursive = 10
  strlen_while     = 10
  strlen(builtin)  = 10
  ✅ All implementations match
--------------------------------------------------
Test 6: "Longer string for test!"
  strlen_simple    = 23
  strlen_glibc     = 24
  strlen_recursive = 23
  strlen_while     = 23
  strlen(builtin)  = 23
  ❌ Mismatch detected!
--------------------------------------------------
Test 7: "With
newline"
  strlen_simple    = 12
  strlen_glibc     = 16
  strlen_recursive = 12
  strlen_while     = 12
  strlen(builtin)  = 12
  ❌ Mismatch detected!
--------------------------------------------------
Test 8: "Embedded"
  strlen_simple    = 8
  strlen_glibc     = 8
  strlen_recursive = 8
  strlen_while     = 8
  strlen(builtin)  = 8
  ✅ All implementations match
--------------------------------------------------
Test 9: "Spaces   inside"
  strlen_simple    = 15
  strlen_glibc     = 16
  strlen_recursive = 15
  strlen_while     = 15
  strlen(builtin)  = 15
  ❌ Mismatch detected!
--------------------------------------------------
Test 10: "abcdefghijklmnopqrstuvwxyz"
  strlen_simple    = 26
  strlen_glibc     = 26
  strlen_recursive = 26
  strlen_while     = 26
  strlen(builtin)  = 26
  ✅ All implementations match
--------------------------------------------------

=== SUMMARY ===
⚠️  Some implementations have discrepancies.

=== PERFORMANCE COMPARISON ===
Performance test (1000000 iterations):
  Simple:   0.043997 seconds
  Glibc:    0.007314 seconds
  Builtin:  0.000374 seconds
  Glibc speedup: 6.02x
[ERROR] Basic tests failed!

[INFO] Running comprehensive test suite...
Starting strlen implementation tests...

=== BASIC FUNCTIONALITY TESTS ===
Testing: ""
  Expected: 0
  Simple:   0
  Glibc:    0
  Builtin:  0
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "a"
  Expected: 1
  Simple:   1
  Glibc:    1
  Builtin:  1
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "ab"
  Expected: 2
  Simple:   2
  Glibc:    2
  Builtin:  2
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "abc"
  Expected: 3
  Simple:   3
  Glibc:    3
  Builtin:  3
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "Hello"
  Expected: 5
  Simple:   5
  Glibc:    8
  Builtin:  5
✅ Simple implementation correct
❌ Glibc implementation correct
✅ Builtin implementation correct
❌ Simple and Glibc match
✅ Simple and Builtin match

Testing: "World!"
  Expected: 6
  Simple:   6
  Glibc:    8
  Builtin:  6
✅ Simple implementation correct
❌ Glibc implementation correct
✅ Builtin implementation correct
❌ Simple and Glibc match
✅ Simple and Builtin match

Testing: "1234567890"
  Expected: 10
  Simple:   10
  Glibc:    10
  Builtin:  10
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "abcdefghijklmnopqrstuvwxyz"
  Expected: 26
  Simple:   26
  Glibc:    26
  Builtin:  26
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

=== EDGE CASE TESTS ===
Testing: ""
  Expected: 0
  Simple:   0
  Glibc:    0
  Builtin:  0
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "a"
  Expected: 1
  Simple:   1
  Glibc:    1
  Builtin:  1
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: " "
  Expected: 1
  Simple:   1
  Glibc:    1
  Builtin:  1
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "  "
  Expected: 2
  Simple:   2
  Glibc:    2
  Builtin:  2
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "   "
  Expected: 3
  Simple:   3
  Glibc:    3
  Builtin:  3
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "
"
  Expected: 1
  Simple:   1
  Glibc:    1
  Builtin:  1
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "	"
  Expected: 1
  Simple:   1
  Glibc:    1
  Builtin:  1
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

"esting: "
  Expected: 1
  Simple:   1
  Glibc:    1
  Builtin:  1
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "Hello
World"
  Expected: 11
  Simple:   11
  Glibc:    11
  Builtin:  11
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing: "Tab	Here"
  Expected: 8
  Simple:   8
  Glibc:    8
  Builtin:  8
✅ Simple implementation correct
✅ Glibc implementation correct
✅ Builtin implementation correct
✅ Simple and Glibc match
✅ Simple and Builtin match

Testing embedded null: "Hello\0World"
  Simple:   5
  Glibc:    8
  Builtin:  5
✅ Simple handles embedded null
❌ Glibc handles embedded null
✅ Builtin handles embedded null

=== LONG STRING TESTS ===
Testing: "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJK"
  Expected: 999
  Simple:   255
  Glibc:    8257
  Builtin:  255
❌ Simple implementation correct
❌ Glibc implementation correct
❌ Builtin implementation correct
❌ Simple and Glibc match
✅ Simple and Builtin match

Testing: "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678"
  Expected: 1999
  Simple:   255
  Glibc:    8257
  Builtin:  255
❌ Simple implementation correct
❌ Glibc implementation correct
❌ Builtin implementation correct
❌ Simple and Glibc match
✅ Simple and Builtin match

Testing: "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefg"
  Expected: 4999
  Simple:   255
  Glibc:    8257
  Builtin:  255
❌ Simple implementation correct
❌ Glibc implementation correct
❌ Builtin implementation correct
❌ Simple and Glibc match
✅ Simple and Builtin match

=== PERFORMANCE TESTS ===
Performance test (1000000 iterations):
  Simple:   0.037269 seconds
  Glibc:    0.008130 seconds
  Builtin:  0.000409 seconds
  Glibc speedup: 4.58x

=== ALIGNMENT STRESS TESTS ===
Offset 0: "Alignment test string"
  Simple:   21
  Glibc:    24
  Builtin:  21
✅ Simple alignment test
❌ Glibc alignment test
✅ Builtin alignment test

Offset 1: "Alignment test string"
  Simple:   21
  Glibc:    23
  Builtin:  21
✅ Simple alignment test
❌ Glibc alignment test
✅ Builtin alignment test

Offset 2: "Alignment test string"
  Simple:   21
  Glibc:    22
  Builtin:  21
✅ Simple alignment test
❌ Glibc alignment test
✅ Builtin alignment test

Offset 3: "Alignment test string"
  Simple:   21
  Glibc:    21
  Builtin:  21
✅ Simple alignment test
✅ Glibc alignment test
✅ Builtin alignment test

Offset 4: "Alignment test string"
  Simple:   21
  Glibc:    21
  Builtin:  21
✅ Simple alignment test
✅ Glibc alignment test
✅ Builtin alignment test

Offset 5: "Alignment test string"
  Simple:   21
  Glibc:    21
  Builtin:  21
✅ Simple alignment test
✅ Glibc alignment test
✅ Builtin alignment test

Offset 6: "Alignment test string"
  Simple:   21
  Glibc:    21
  Builtin:  21
✅ Simple alignment test
✅ Glibc alignment test
✅ Builtin alignment test

Offset 7: "Alignment test string"
  Simple:   21
  Glibc:    26
  Builtin:  21
✅ Simple alignment test
❌ Glibc alignment test
✅ Builtin alignment test

=== TEST SUMMARY ===
Total tests: 132
Passed: 111
Failed: 21
Success rate: 84.1%
⚠️  Some tests failed. Check implementation.
[ERROR] Comprehensive tests failed!

[WARNING] Valgrind not found. Skipping memory tests.

[INFO] Running performance tests...
Performance comparison (this may take a moment)...
=== PERFORMANCE COMPARISON ===
Performance test (1000000 iterations):
  Simple:   0.027696 seconds
  Glibc:    0.005825 seconds
  Builtin:  0.000319 seconds
  Glibc speedup: 4.75x
[SUCCESS] Performance tests completed!
[ERROR] Some tests failed!

```
