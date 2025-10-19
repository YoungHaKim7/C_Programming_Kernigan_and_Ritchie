# Result

- `make clean`
- `make all`
- `make run`
- `make test`

```bash
# make clean
$ make clean
rm -rf target

# make all
$ make all
mkdir -p target
gcc -Wall -Wextra -std=c99 -g -o target/pointers_and_arrays src/pointers_and_arrays.c
mkdir -p target
gcc -Wall -Wextra -std=c99 -g -o target/test_pointers_arrays src/test_pointers_arrays.c

# make run
$ make run
./target/pointers_and_arrays
=== Pointers and Arrays Examples ===

1. Basic array and pointer assignment:
   a[0] = 0, *pa = 0
   Address of a[0]: 0x16d05e300, pa: 0x16d05e300

2. Pointer arithmetic:
   *(pa+1) = 1 (should be a[1] = 1)
   *(pa+3) = 3 (should be a[3] = 3)
   pa+2 points to address: 0x16d05e308
   &a[2] is at address: 0x16d05e308

3. Array indexing vs pointer arithmetic:
   a[0] = 0, *(a+0) = 0, *(pa+0) = 0
   a[1] = 1, *(a+1) = 1, *(pa+1) = 1
   a[2] = 2, *(a+2) = 2, *(pa+2) = 2
   a[3] = 3, *(a+3) = 3, *(pa+3) = 3
   a[4] = 4, *(a+4) = 4, *(pa+4) = 4

4. Address equivalence:
   &a[0] = 0x16d05e300, a+0 = 0x16d05e300
   &a[1] = 0x16d05e304, a+1 = 0x16d05e304
   &a[2] = 0x16d05e308, a+2 = 0x16d05e308

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
    Array name 'message' = 0x16d05e230
    &message[0] = 0x16d05e230
    message[0] = 'P'
    *message = 'P'
    msg_ptr = message, msg_ptr[1] = 'o'

# make test
$ make test
./target/test_pointers_arrays
=== Running Pointer and Array Tests ===

Testing pointer arithmetic...
✓ Pointer arithmetic tests passed

Testing array-pointer equivalence...
✓ Array-pointer equivalence tests passed

Testing strlen implementation...
✓ strlen tests passed

Testing subarray operations...
✓ Subarray tests passed

Testing pointer operations...
✓ Pointer operations tests passed

Testing string pointer operations...
✓ String pointer tests passed

🎉 All tests passed successfully!
```
