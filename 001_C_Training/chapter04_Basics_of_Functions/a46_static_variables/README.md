# Result

```bash
/opt/homebrew/opt/gcc@15/bin/gcc-15 -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a46_static_variables ./src/main.c
./target/a46_static_variables

=== Example 1 — File-scope static ===
Initial file_static_counter = 0
[helper_increment] file_static_counter = 1
[helper_increment] file_static_counter = 2

=== Example 2 — Static local variable ===
[demo_static_local] called 1 times
[demo_static_local] called 2 times
[demo_static_local] called 3 times

=== Example 3 — Static variable inside loop ===
[demo_static_in_loop] loop_static = 110
[demo_static_in_loop] loop_static = 120
[demo_static_in_loop] loop_static = 130
[demo_static_in_loop] loop_static = 140
[demo_static_in_loop] loop_static = 150
[demo_static_in_loop] loop_static = 160

=== Example 4 — Static variable inside conditional ===
[demo_static_conditional] cond_static = 5
[demo_static_conditional] cond_static = 10

✅ All static variable examples completed successfully.
```
