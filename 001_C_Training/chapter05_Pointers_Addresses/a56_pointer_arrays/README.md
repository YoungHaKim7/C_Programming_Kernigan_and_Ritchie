# Result

```bash
=== Chapter 5.6: Pointer Arrays; Pointers to Pointers ===

Example 1: Basic Pointer Array Declaration
-----------------------------------------
Array of fruit names:
  fruits[0] = "apple" (address: 0x1027320b0)
  fruits[1] = "banana" (address: 0x1027320b8)
  fruits[2] = "cherry" (address: 0x1027320c0)
  fruits[3] = "date" (address: 0x1027320c8)

Example 2: Pointer Arrays with Dynamic Allocation
-----------------------------------------------
Dynamically assigned names:
  names[0] = "Alice" (length: 5)
  names[1] = "Bob" (length: 3)
  names[2] = "Charlie" (length: 7)
  names[3] = "David" (length: 5)
  names[4] = "Eve" (length: 3)

Example 3: Sorting with Pointer Arrays
-------------------------------------
Before sorting:
  zebra
  apple
  orange
  banana
  grape
  kiwi
  mango
  pear
After sorting:
  apple
  banana
  grape
  kiwi
  mango
  orange
  pear
  zebra

Example 4: Pointers to Pointers
-----------------------------
Original array:
  colors[0] = "red"
  colors[1] = "green"
  colors[2] = "blue"

Using pointer to pointer:
  *(ptr_to_colors + 0) = "red"
  *(ptr_to_colors + 1) = "green"
  *(ptr_to_colors + 2) = "blue"

Dereferencing twice:
  *(*(ptr_to_colors + 0) + 0) = 'r'
  *(*(ptr_to_colors + 1) + 0) = 'g'
  *(*(ptr_to_colors + 2) + 0) = 'b'

Example 5: Memory Layout of Pointer Arrays
------------------------------------------
Memory layout of pointer array:
  Element 0:
    Pointer address: 0x16d6ce3c0
    Points to: 0x1027322c8
    String value: "short"
    String length: 5
  Element 1:
    Pointer address: 0x16d6ce3c8
    Points to: 0x1027322d0
    String value: "medium_length"
    String length: 13
  Element 2:
    Pointer address: 0x16d6ce3d0
    Points to: 0x1027322e0
    String value: "very_long_string_that_takes_more_space"
    String length: 38

Example 6: Pointer Arithmetic with Pointer Arrays
-------------------------------------------------
Pointer arithmetic demonstration:
  Base address: 0x16d6ce3b8
  *ptr = "alpha"
  *(ptr + 1) = "beta"
  *(ptr + 2) = "gamma"
  ptr[3] = "delta"

Incrementing pointer:
  After ptr++, *ptr = "beta"
  New address: 0x16d6ce3c0

Example 7: Two-dimensional Arrays vs Pointer Arrays
--------------------------------------------------
2D array:
  two_d[0] = "first" (size: 20 bytes)
  two_d[1] = "second" (size: 20 bytes)
  two_d[2] = "third" (size: 20 bytes)
Pointer array:
  ptr_array[0] = "first" (pointer size: 8 bytes)
  ptr_array[1] = "second" (pointer size: 8 bytes)
  ptr_array[2] = "third" (pointer size: 8 bytes)

Example 8: Command-line Arguments Simulation
--------------------------------------------
Simulated command line: program arg1 arg2 arg3 arg4
Arguments:
  argv[1] = "arg1"
  argv[2] = "arg2"
  argv[3] = "arg3"
  argv[4] = "arg4"

Example 9: Array of Function Pointers
-------------------------------------
Comparing "Hello" and "hello":
  Case-sensitive: -32

Example 10: Complete Sorting Program Demonstration
-------------------------------------------------
Original lines:
  This is a demonstration
  of pointer arrays
  and how they work
  for sorting text
  efficiently

Sorted lines:
  This is a demonstration
  and how they work
  efficiently
  for sorting text
  of pointer arrays
```
