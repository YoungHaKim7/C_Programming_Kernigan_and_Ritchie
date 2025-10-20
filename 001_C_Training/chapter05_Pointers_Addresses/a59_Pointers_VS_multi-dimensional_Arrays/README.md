# Summary

- I've created a comprehensive C program that demonstrates the concepts from Chapter 5.9 of Kernighan and Ritchie, including:

- Key Features:
  - 1. Array vs Pointer Array Comparison: Demonstrates the difference between int a[3][4] and int *b[3], showing memory layout and the ability to have
variable-length rows with pointer arrays.
  - 2. String Arrays: Shows the difference between char *name[] and char aname[][15], demonstrating memory efficiency for strings of varying lengths.
  - 3. Rewritten Date Functions:
    - day_of_year_pointers(): Uses pointer arithmetic instead of array indexing
    - month_day_pointers(): Uses pointer arithmetic instead of array indexing
  - 4. 10 Comprehensive Test Cases: Including leap years, non-leap years, century years, and various edge cases.
  - 5. Advanced Demonstrations:
    - Memory layout visualization
    - Row-major order calculations
    - Pointer arithmetic on 2D arrays
    - Month name function using pointer arrays

- Key Insights Demonstrated:
  - 2D Arrays: Contiguous memory with fixed row sizes
  - Pointer Arrays: Separate allocation for each row, allowing variable lengths
  - Memory Efficiency: Pointer arrays are more efficient for strings of different lengths
  - Row-Major Order: How C calculates positions in multi-dimensional arrays

- The program successfully compiles and runs, providing clear examples of all the concepts discussed in the textbook section

# Result

```bash
Chapter 5.9: Pointers vs Multi-dimensional Arrays
================================================
=== Demonstrating Array vs Pointer Array Differences ===
Two-dimensional array a[3][4]:
a[0][0] = 1 (address: 0x16d5fe448)
a[0][1] = 2 (address: 0x16d5fe44c)
a[0][2] = 3 (address: 0x16d5fe450)
a[0][3] = 4 (address: 0x16d5fe454)
a[1][0] = 5 (address: 0x16d5fe458)
a[1][1] = 6 (address: 0x16d5fe45c)
a[1][2] = 7 (address: 0x16d5fe460)
a[1][3] = 8 (address: 0x16d5fe464)
a[2][0] = 9 (address: 0x16d5fe468)
a[2][1] = 10 (address: 0x16d5fe46c)
a[2][2] = 11 (address: 0x16d5fe470)
a[2][3] = 12 (address: 0x16d5fe474)

Array of pointers b[3]:
b[0][0] = 1 (address: 0x16d5fe420)
b[0][1] = 2 (address: 0x16d5fe424)
b[0][2] = 3 (address: 0x16d5fe428)
b[0][3] = 4 (address: 0x16d5fe42c)
b[1][0] = 5 (address: 0x16d5fe410)
b[1][1] = 6 (address: 0x16d5fe414)
b[1][2] = 7 (address: 0x16d5fe418)
b[1][3] = 8 (address: 0x16d5fe41c)
b[2][0] = 9 (address: 0x16d5fe400)
b[2][1] = 10 (address: 0x16d5fe404)
b[2][2] = 11 (address: 0x16d5fe408)
b[2][3] = 12 (address: 0x16d5fe40c)

=== Different Row Lengths with Pointer Array ===
Row 0 (length 2): 100 200
Row 1 (length 6): 300 400 500 600 700 800
Row 2 (length 1): 900

=== String Arrays: Pointers vs 2D Array ===
Array of pointers:
name[0] = "Illegal month" (length: 13)
name[1] = "Jan" (length: 3)
name[2] = "Feb" (length: 3)
name[3] = "Mar" (length: 3)
name[4] = "Apr" (length: 3)
name[5] = "May" (length: 3)
name[6] = "Jun" (length: 3)

Two-dimensional array:
aname[0] = "Illegal month" (length: 13)
aname[1] = "Jan" (length: 3)
aname[2] = "Feb" (length: 3)
aname[3] = "Mar" (length: 3)
aname[4] = "Apr" (length: 3)
aname[5] = "May" (length: 3)
aname[6] = "Jun" (length: 3)

Memory usage comparison:
Array of pointers: 56 bytes for pointers + string storage
2D array: 105 bytes (fixed size for all strings)

=== Month Name Function ===
Month  0: Illegal month
Month  1: January
Month  2: February
Month  3: March
Month  4: April
Month  5: May
Month  6: June
Month  7: July
Month  8: August
Month  9: September
Month 10: October
Month 11: November
Month 12: December

=== Advanced Pointer Manipulation ===
Matrix using pointer arithmetic:
Element 0: 10
Element 1: 20
Element 2: 30
Element 3: 40
Element 4: 50
Element 5: 60
Element 6: 70
Element 7: 80
Element 8: 90
Element 9: 100
Element 10: 110
Element 11: 120

Row-major order access:
matrix[0][0] = 10 (computed as *(&matrix[0][0] + 4*0 + 0))
matrix[0][1] = 20 (computed as *(&matrix[0][0] + 4*0 + 1))
matrix[0][2] = 30 (computed as *(&matrix[0][0] + 4*0 + 2))
matrix[0][3] = 40 (computed as *(&matrix[0][0] + 4*0 + 3))
matrix[1][0] = 50 (computed as *(&matrix[0][0] + 4*1 + 0))
matrix[1][1] = 60 (computed as *(&matrix[0][0] + 4*1 + 1))
matrix[1][2] = 70 (computed as *(&matrix[0][0] + 4*1 + 2))
matrix[1][3] = 80 (computed as *(&matrix[0][0] + 4*1 + 3))
matrix[2][0] = 90 (computed as *(&matrix[0][0] + 4*2 + 0))
matrix[2][1] = 100 (computed as *(&matrix[0][0] + 4*2 + 1))
matrix[2][2] = 110 (computed as *(&matrix[0][0] + 4*2 + 2))
matrix[2][3] = 120 (computed as *(&matrix[0][0] + 4*2 + 3))

=== Testing Date Functions ===
Test 1: 2024/01/01
  Day of year - Original: 1, Pointers: 1 ✓
  Month/Day - Original: 1/1, Pointers: 1/1 ✓
Test 2: 2024/02/29
  Day of year - Original: 60, Pointers: 60 ✓
  Month/Day - Original: 2/29, Pointers: 2/29 ✓
Test 3: 2024/12/31
  Day of year - Original: 366, Pointers: 366 ✓
  Month/Day - Original: 12/31, Pointers: 12/31 ✓
Test 4: 2023/02/28
  Day of year - Original: 59, Pointers: 59 ✓
  Month/Day - Original: 2/28, Pointers: 2/28 ✓
Test 5: 2023/12/31
  Day of year - Original: 365, Pointers: 365 ✓
  Month/Day - Original: 12/31, Pointers: 12/31 ✓
Test 6: 2000/02/29
  Day of year - Original: 60, Pointers: 60 ✓
  Month/Day - Original: 2/29, Pointers: 2/29 ✓
Test 7: 1900/02/28
  Day of year - Original: 59, Pointers: 59 ✓
  Month/Day - Original: 2/28, Pointers: 2/28 ✓
Test 8: 2024/07/04
  Day of year - Original: 186, Pointers: 186 ✓
  Month/Day - Original: 7/4, Pointers: 7/4 ✓
Test 9: 2023/03/15
  Day of year - Original: 74, Pointers: 74 ✓
  Month/Day - Original: 3/15, Pointers: 3/15 ✓
Test 10: 2024/10/31
  Day of year - Original: 305, Pointers: 305 ✓
  Month/Day - Original: 10/31, Pointers: 10/31 ✓

=== Memory Layout Demonstration ===
2D array a[2][3]:
a[0][0] = 1 at 0x16d5fe4c0
a[0][1] = 2 at 0x16d5fe4c4
a[0][2] = 3 at 0x16d5fe4c8
a[1][0] = 4 at 0x16d5fe4cc
a[1][1] = 5 at 0x16d5fe4d0
a[1][2] = 6 at 0x16d5fe4d4
Flattened view: 1 2 3 4 5 6

```
