# Result

```bash
/opt/homebrew/opt/gcc@15/bin/gcc-15 -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a44_scope_rules ./src/main.c
./target/a44_scope_rules
=== Example 1 — Simple global definition ===
x = 42

=== Example 2 — Declaration without definition (simulated) ===
// (In single-file demo, this works because global_x is defined above)
extern global_x = 42

=== Example 3 — Simulated separate definition file ===
counter = 100

=== Example 4 — push/pop with extern vars ===
pop1 = 20.5
pop2 = 10.5

=== Example 5 — Multiple extern declarations allowed ===
total = 5

=== Example 6 — extern + initialization ===
val = 123

=== Example 7 — extern inside a function ===
counter (extern inside block) = 10

=== Example 8 — extern with arrays ===
10 20 30

=== Example 9 — extern with functions ===
Hello from greet!

=== Example 10 — Global shared across sections ===
mode = 42
mode = 99

✅ All 10 extern examples completed successfully.
```
