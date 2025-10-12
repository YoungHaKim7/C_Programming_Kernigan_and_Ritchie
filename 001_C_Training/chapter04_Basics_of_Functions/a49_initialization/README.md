# Result

```bash

/opt/gcc-15/bin/gcc -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a49_initialization ./src/main.c
./target/a49_initialization
=== 4.9 Initialization Examples ===

1️⃣ Hello from printf initializer!

=== Combined Declarations ===
a (uninitialized, garbage) = 0 (undefined)
b = 10, c = 15, d (printf returned) = 39
x=1, y=3, z=9
squote=''', newline below:
<-- newline
reg_x (register) = 123
uninit_static (static, default) = 0
static_global = 42
milliseconds_per_day = 86400000

=== Behavior Demonstrations ===
🔹 static_example() called 1 times
🔹 static_example() called 2 times
🔹 static_example() called 3 times
Global vars: counter=0, pi=0.000000, ms/day=86400000

=== Binary Search Examples ===
Sorted array: 2 4 7 11 15 19 23 28 31 42

Searching for 7: Found at index 2
Searching for 15: Found at index 4
Searching for 42: Found at index 9
Searching for 2: Found at index 0
Searching for 99: Not found
Searching for -5: Not found
Searching for 23: Found at index 6

=== End of Initialization Examples ===

```
