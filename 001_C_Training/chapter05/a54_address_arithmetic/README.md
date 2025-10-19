# Chapter 5.4: Address Arithmetic

This implementation demonstrates the concepts from Section 5.4 of "The C Programming Language" by Kernighan and Ritchie.

## Key Concepts Implemented

1. **Simple Memory Allocator**: `alloc()` and `afree()` functions that manage a static buffer using pointer arithmetic.

2. **Pointer Arithmetic Operations**:
   - Pointer increment (`p++`)
   - Pointer addition (`p + n`)
   - Pointer subtraction (`p - q`)
   - Pointer comparisons

3. **String Length Function**: `strlen()` implementation using pointer arithmetic instead of array indexing.

4. **Array-Pointer Equivalence**: Demonstrates that `a[i]` is equivalent to `*(a + i)`.

## Files

- `alloc.c`: Main implementation with all examples and test cases
- `Makefile`: Build configuration
- `README.md`: This file

## Compilation and Execution

```bash
# Compile the program
make

# Run the tests
make run

# Or run tests explicitly
make test

# Clean build artifacts
make clean
```

## Test Cases

The program includes 8 comprehensive test functions:

1. **test_alloc_afree()**: Tests the memory allocation and deallocation
2. **test_pointer_arithmetic()**: Demonstrates pointer increment, addition, and subtraction
3. **test_strlen()**: Tests the custom strlen function
4. **test_pointer_comparisons()**: Shows pointer comparison operations
5. **test_array_pointer_equivalence()**: Demonstrates array notation vs pointer notation
6. **test_pointer_and_null()**: Tests NULL pointer usage
7. **test_memory_alignment()**: Shows memory alignment for different data types

## Key Features Demonstrated

- Static buffer allocation with `static char allocbuf[ALLOCSIZE]`
- Pointer arithmetic with automatic scaling based on data type size
- Safe pointer bounds checking
- Stack-based memory management (LIFO)
- NULL pointer handling
- Pointer comparison semantics
- Memory alignment considerations

# Result


```bash
Chapter 5.4: Address Arithmetic Examples
========================================
=== Testing alloc and afree ===
Allocated 100 chars at 0x102608008
Allocated 200 chars at 0x10260806c
Allocated 300 chars at 0x102608134
Buffer usage: 600/10000 bytes
Freed p3, buffer usage: 300/10000 bytes
Freed p2, buffer usage: 100/10000 bytes
Freed p1, buffer usage: 0/10000 bytes

=== Testing Pointer Arithmetic ===
Array elements: 10 20 30 40 50
Pointer arithmetic demonstrations:
p points to: 10 (address 0x16d7fe4f8)
p+1 points to: 20 (address 0x16d7fe4fc)
p+2 points to: 30 (address 0x16d7fe500)
Pointer increment:
After p++, p points to: 20 (address 0x16d7fe4fc)
Pointer addition:
After p+=2, p points to: 40 (address 0x16d7fe504)
Pointer subtraction:
p - arr = 3 (elements between them)

=== Testing strlen with Pointer Arithmetic ===
String: "Hello" has length 5
String: "C Programming" has length 13
String: "" has length 0
String: "Pointer arithmetic is cool!" has length 27

=== Testing Pointer Comparisons ===
Array: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
start points to: 1
middle points to: 5
end points to: 10
Pointer comparisons:
start < middle: true
middle < end: true
start == middle: false
start != end: true

=== Testing Array-Pointer Equivalence ===
Using array notation:
arr[0] = 100 (address 0x16d7fe500)
arr[1] = 200 (address 0x16d7fe504)
arr[2] = 300 (address 0x16d7fe508)
arr[3] = 400 (address 0x16d7fe50c)
arr[4] = 500 (address 0x16d7fe510)

Using pointer notation:
*(arr+0) = 100 (address 0x16d7fe500)
*(arr+1) = 200 (address 0x16d7fe504)
*(arr+2) = 300 (address 0x16d7fe508)
*(arr+3) = 400 (address 0x16d7fe50c)
*(arr+4) = 500 (address 0x16d7fe510)

Using pointer variable:
p[0] = 100 (address 0x16d7fe500)
p[1] = 200 (address 0x16d7fe504)
p[2] = 300 (address 0x16d7fe508)
p[3] = 400 (address 0x16d7fe50c)
p[4] = 500 (address 0x16d7fe510)

=== Testing NULL Pointer ===
NULL pointer value: 0x0
Alloc successful, pointer is not NULL: 0x102608008
Big allocation failed as expected (returned NULL)

=== Testing Memory Alignment ===
int pointer address: 0x10260803a (alignment: 2)
double pointer address: 0x10260804e (alignment: 6)
char pointer address: 0x102608066
Stored integers: 100 200 300 400 500
Stored doubles: 3.14 6.28 9.42

All tests completed successfully!

```
