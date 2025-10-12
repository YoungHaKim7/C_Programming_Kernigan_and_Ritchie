# Result

```bash

=== Pointer & and * Operator Examples ===

Initial values: x=1, y=2

ip = &x;  // ip now points to x
Address of x: 0x7ffcbdce85a4
Value of ip : 0x7ffcbdce85a4
*ip (value at ip) = 1

y = *ip;  // y is now 1 (same as x)
*ip = 0;  // x is now 0

ip = &z[0];  // ip now points to z[0]
Address of z[0]: 0x7ffcbdce8570
Value of *ip (z[0]) = 99

*(ip + 1) = 55;  // z[1] changed to 55
*jp = 123;  // z[0] = 123

Final values:
x=0, y=1, z[0]=123, z[1]=55
ip points to 0x7ffcbdce8570 (value=123)
jp points to 0x7ffcbdce8570 (value=123)

=== End of Pointer Example ===

```

# 🧠 Key Concepts Illustrated

|Concept|	Code Example|	Meaning|
|-|-|-|
|Address-of operator `&`|	ip = &x;|	Stores the memory address of `x` into pointer `ip`|
|Dereference operator `*`|	y = *ip;|	Accesses the value stored at address `ip`|
|Pointer assignment|	`ip = &z[0];`|	Pointer can point to another variable or array element|
|Pointer arithmetic|	`*(ip + 1) = 55;`|	Moves to next integer in array|
|Invalid uses	|`&10, &(x+y)`|	`&` can only be used on variables or array elements|
|Register restriction	|`register int r;``|	`&r` is illegal|
