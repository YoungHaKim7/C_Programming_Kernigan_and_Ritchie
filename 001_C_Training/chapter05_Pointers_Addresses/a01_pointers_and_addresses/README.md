# Result

```bash
main.c:50:11: warning: unused variable ‘func_ptr’ [-Wunused-variable]
   50 |     int (*func_ptr)(int, int) = NULL;
      |           ^~~~~~~~
[2/2] Linking C executable target/a01_pointers_and_addresses
mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
./build/./target/a01_pointers_and_addresses
=== Pointer Examples ===

1. Basic pointer declaration and assignment:
   Value of x: 42
   Address of x: 0x7ffcb3edb914
   Pointer ptr points to: 0x7ffcb3edb914
   Value pointed to by ptr: 42

2. Pointer arithmetic:
   First element: 10
   Second element (arr_ptr + 1): 20
   Third element (arr_ptr + 2): 30

3. Pointer to pointer:
   Value of y: 100
   Value pointed to by p1: 100
   Value pointed to by *p2: 100

4. Null pointer:
   Null pointer value: (nil)
   Pointer is NULL

5. Pointer to char (string):
   String: Hello, World!
   First character: H
   Second character: e

6. Function pointer:
   Function pointer declared

7. Pointer and array relationship:
   Array access using []: 3
   Pointer access using *: 3
   Array size using sizeof: 20
   Pointer size: 8

8. Dynamic memory allocation simulation:
   Dynamically allocated value: 999
   Address of dynamically allocated: 0x7ffcb3edb8cc

9. Pointer comparison:
   Address of a: 0x7ffcb3edb8c8
   Address of b: 0x7ffcb3edb8c4
   ptr_a < ptr_b: false

10. Pointer with different data types:
    Char value: A, size: 1 bytes
    Short value: 32767, size: 2 bytes
    Long value: 1234567890, size: 8 bytes
```
