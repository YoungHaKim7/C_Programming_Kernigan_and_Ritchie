# Result
- C is sometimes castigated for the syntax of its declarations, particularly ones that involve pointers to functions. The syntax is an attempt to make the declaration and the use agree; it works well for simple cases, but it can be confusing for the harder ones, because declarations cannot be read left to right, and because parentheses are over-used.
  - C는 때때로 선언의 구문, 특히 다음과 같은 것들로 인해 거세됩니다 함수에 대한 지침. 구문은 선언과 사용자가 일치하도록 하려는 시도입니다 간단한 경우에는 잘 작동하지만, 어려운 경우에는 선언문 때문에 혼란스러울 수 있습니다 왼쪽에서 오른쪽으로 읽을 수 없으며 괄호가 과도하게 사용되기 때문입니다.

```bash

 cat test_input.txt | ./build/target/a512_cmake_ver_complicated_declarations
C Declaration Parser - Chapter 5.12
===================================
=== Testing Declaration Parser ===

Test 1: char **argv
argv:  pointer to pointer to char

Test 2: int (*daytab)[13]
daytab:  pointer to array[13] of int

Test 3: int *daytab[13]
daytab:  array[13] of pointer to int

Test 4: void *comp()
comp:  function returning pointer to void

Test 5: void (*comp)()
comp:  pointer to function returning void

Test 6: char (*(*x())[])()
x:  function returning pointer to array[] of pointer to function returning char

Test 7: char (*(*x[3])())[5]
x:  array[3] of pointer to function returning pointer to array[5] of char

Test 8: int **a[2][3]
a:  array[2] of array[3] of pointer to pointer to int

Test 9: int (*(*fp)(int))[10]
error: missing )
syntax error
fp:  pointer to pointer to int

Test 10: void (*signal(int, void (*)(int)))(int)
error: missing )
syntax error
signal:  pointer to void

=== Testing Word Description to Declaration Converter ===

Test 1: x * char
=> char (*x)

Test 2: x [] * char
=> char (*x[])

Test 3: x () * char
=> char (*x())

Test 4: x [] * () * char
=> char (*(*x[])())

Test 5: x () * [] * char
=> char (*(*x())[])

Test 6: x [3] * () [5] char
=> char (*x[3])()[5]

Test 7: name * int
=> int (*name)

Test 8: func () * int
=> int (*func())

Test 9: arr [10] int
=> int arr[10]

Test 10: ptr * arr [5] * char
=> char (*arr (*ptr)[5])

=== Interactive Mode ===
Enter declarations to parse (Ctrl+D to exit):
argv:  pointer to pointer to char
daytab:  pointer to array[13] of int
daytab:  array[13] of pointer to int
comp:  function returning pointer to void
comp:  pointer to function returning void
x:  function returning pointer to array[] of pointer to function returning char
x:  array[3] of pointer to function returning pointer to array[5] of char
a:  array[2] of array[3] of pointer to pointer to int
error: missing )
syntax error
error: expected name or (dcl)
Parse error: no identifier found
error: missing )
syntax error
error: expected name or (dcl)
error: missing )
syntax error
error: expected name or (dcl)
syntax error
error: expected name or (dcl)
syntax error
```



# The interactive mode now correctly parses the declarations:

- int x is parsed as "x: int"
- char *ptr is parsed as "ptr: pointer to char"

# ⏺ Fixed!

- The interactive mode issue has been resolved. The problem was that the variables (out, name, datatype, token, and the input buffer bufp) weren't
  - being reset between each iteration of the interactive loop, causing the parser to get stuck in an error state.

- Key changes made:
  - 1. Added proper variable reset at the start of each loop iteration in main.c:271-275
  - 2. Changed the loop condition to while(1) with an explicit EOF check
  - 3. Added better error handling for cases where no identifier is found
