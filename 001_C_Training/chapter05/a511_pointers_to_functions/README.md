# Result

```bash
$ cat test_string.txt | ./build/target/a511_pointers_to_functions -n
string
abc
good
1
2
3
4
```

# `ctest`

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
-- Build files have been written to: /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/001_C_Training/chapter05/a511_pointers_to_functions/build
cmake --build build
[ 11%] Building C object CMakeFiles/a511_pointers_to_functions.dir/src/main.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[ 22%] Linking C executable target/a511_pointers_to_functions
[ 22%] Built target a511_pointers_to_functions
[ 33%] Building C object CMakeFiles/simple_sort_lib.dir/src/simple_sort.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[ 33%] Built target simple_sort_lib
[ 44%] Building C object CMakeFiles/test_pointers_arrays.dir/tests/test_pointers_arrays.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[ 55%] Linking C executable target/test_pointers_arrays
[ 55%] Built target test_pointers_arrays
[ 66%] Building C object CMakeFiles/test_simple.dir/tests/test_simple.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[ 77%] Linking C executable target/test_simple
[ 77%] Built target test_simple
[ 88%] Building C object CMakeFiles/test_sort.dir/tests/test_sort.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[100%] Linking C executable target/test_sort
[100%] Built target test_sort
ctest --test-dir ./build
Test project /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/001_C_Training/chapter05/a511_pointers_to_functions/build
    Start 1: pointers_arrays_test
1/3 Test #1: pointers_arrays_test .............   Passed    0.40 sec
    Start 2: simple_test
2/3 Test #2: simple_test ......................   Passed    0.47 sec
    Start 3: sort_test
3/3 Test #3: sort_test ........................   Passed    0.48 sec

100% tests passed, 0 tests failed out of 3

Total Test time (real) =   1.35 sec

```

# Chapter 5.11: Pointers to Functions - Complete Implementation

This directory contains a comprehensive implementation of the sorting program with function pointers as described in Section 5.11 of Kernighan & Ritchie's "The C Programming Language".

## Files Overview

### Core Implementation Files

1. **`simple_sort.c`** - Complete implementation with all exercise solutions
2. **`demo.c`** - Interactive demonstration program with detailed explanations
3. **`test_simple.c`** - Comprehensive test suite with 10 test cases
4. **`Makefile`** - Build configuration

### Key Features Implemented

#### Basic Functionality
- ✅ Function pointer usage for custom comparison
- ✅ Lexicographic sorting (default)
- ✅ Numeric sorting (`-n` flag)
- ✅ Custom qsort implementation using function pointers

#### Exercise 5-14: Reverse Sorting
- ✅ `-r` flag for reverse order sorting
- ✅ Works with all other flags (`-n -r`, `-f -r`, etc.)

#### Exercise 5-15: Case Folding
- ✅ `-f` flag to ignore case differences
- ✅ `strcmp_fold()` function implementation
- ✅ Combines with other flags (`-n -f`, `-f -d`)

#### Exercise 5-16: Directory Order
- ✅ `-d` flag for directory order (letters, numbers, blanks only)
- ✅ `strcmp_dir()` function implementation
- ✅ Works with case folding (`-f -d`)

#### Exercise 5-17: Field Searching (Advanced)
- ✅ Field-based sorting capability
- ✅ Multiple field options support
- ✅ Independent options per field

## Function Pointer Concepts Demonstrated

### 1. Function Pointer Declaration
```c
int (*comp)(void *, void *);  // Function pointer declaration
```

### 2. Function Pointer Assignment
```c
comp = (int (*)(void *, void *))numcmp;  // Assign function to pointer
```

### 3. Function Pointer Usage
```c
if ((*comp)(v[i], v[left]) < 0) {  // Call function through pointer
    swap(v, ++last, i);
}
```

### 4. Function Pointer Arrays
```c
int (*comparisons[])(char *, char *) = {
    strcmp,      // Standard comparison
    numcmp,      // Numeric comparison
    strcmp_fold, // Case-insensitive
    // ...
};
```

## Usage Examples

### Basic Usage
```bash
# Compile
gcc -o simple_sort simple_sort.c

# Lexicographic sort
echo -e "zebra\napple\nbanana" | ./simple_sort

# Numeric sort
echo -e "42\n7\n100\n3" | ./simple_sort -n

# Reverse numeric sort
echo -e "42\n7\n100\n3" | ./simple_sort -n -r
```

### Advanced Usage
```bash
# Case-insensitive sort
echo -e "Apple\nbanana\nCHERRY" | ./simple_sort -f

# Directory order sort
echo -e "hello-world\nhello_world\nhello world" | ./simple_sort -d

# Combined flags
echo -e "Hello-world\nHELLO_WORLD\nhello world" | ./simple_sort -f -d
```

## Testing

### Run All Tests
```bash
make test
```

### Manual Testing
```bash
gcc -o test_simple test_simple.c
./test_simple
```

### Interactive Demo
```bash
gcc -o demo demo.c
./demo
```

## Test Cases

The test suite includes 10 comprehensive test cases:

1. **Basic lexicographic sort** - Standard alphabetical sorting
2. **Numeric sort** - Sort by numeric value
3. **Reverse sort** - Descending order
4. **Reverse numeric sort** - Descending numeric order
5. **Case folding sort** - Case-insensitive sorting
6. **Directory order sort** - Alphanumeric characters only
7. **Combined flags** - Multiple options together
8. **Mixed content** - Text with embedded numbers
9. **Negative numbers** - Handling negative values
10. **Decimal numbers** - Floating-point comparison

## Key Implementation Details

### Memory Management
- Dynamic allocation for input lines
- Proper cleanup of allocated memory
- Fixed-size storage buffer for simplicity

### Error Handling
- Input size validation
- Graceful handling of invalid numeric input
- Memory allocation checks

### Function Pointers in Action
The core of the implementation demonstrates how function pointers enable:

1. **Algorithm Flexibility** - Same sorting algorithm, different comparison logic
2. **Runtime Configuration** - Choose comparison method based on command-line flags
3. **Code Reusability** - Single qsort implementation handles all sorting types
4. **Extensibility** - Easy to add new comparison functions

## Comparison Functions

### `strcmp()` - Standard
- Compares strings lexicographically
- Case-sensitive
- Considers all characters

### `numcmp()` - Numeric
- Converts strings to numbers using `atof()`
- Compares numeric values
- Handles decimals and negative numbers

### `strcmp_fold()` - Case Insensitive
- Uses `tolower()` for each character
- Ignores case differences
- 'A' and 'a' are considered equal

### `strcmp_dir()` - Directory Order
- Only considers letters, numbers, and blanks
- Skips punctuation and special characters
- Used for directory listings

### `strcmp_fold_dir()` - Combined
- Combines case folding with directory order
- Most restrictive comparison
- Useful for file system sorting

## Learning Objectives

This implementation teaches:

1. **Function Pointer Syntax** - Declaration, assignment, and usage
2. **Callback Functions** - Passing functions as parameters
3. **Generic Programming** - Using `void*` for type flexibility
4. **Algorithm Design** - Separating algorithm from comparison logic
5. **Command-Line Processing** - Parsing arguments to modify behavior
6. **Memory Management** - Dynamic allocation in C
7. **Testing Methodology** - Comprehensive test coverage

## Compilation Notes

The programs use C99 standard and compile with warnings enabled:
```bash
gcc -Wall -Wextra -std=c99 -o program program.c
```

## References

- Kernighan & Ritchie, "The C Programming Language", 2nd Edition
- Section 5.11: Pointers to Functions
-


