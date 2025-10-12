# Result

```bash
/opt/homebrew/opt/gcc@15/bin/gcc-15 -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a46_static_variables ./src/main.c
./target/a48_block_structure

1️⃣ Global scope: x = 10, y = 20
2️⃣ Inner block: x = 1 (local hides global)
3️⃣ After inner block: x = 10 (global again)
4️⃣ Inside if: i = 100
5️⃣ for loop i = 0
5️⃣ for loop i = 1
5️⃣ for loop i = 2
6️⃣ Nested inner a = 20
7️⃣ Outer a = 10
8️⃣ Local x hides global: x = 3.14
9️⃣ Loop iteration 0, counter = 1
9️⃣ Loop iteration 1, counter = 1
🔟 z inside block = 50
🧩 printf name hidden here
🧮 temp = 123 (alive)
🏁 Deepest level a = 3
🏁 Middle level a = 2
🏁 Outer level a = 1
```

- Example	Concept
  - 1–3 :	Global vs. local variables
  - 4	: if-block local variable
  - 5	: for-loop variable scope
  - 6–7	: Nested blocks and variable shadowing
  - 8	: Local variable hiding global function name
  - 9	: Automatic variable lifetime per block
  - 10 : Multiple nested shadowing
