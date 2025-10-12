#include <stdio.h>

int x = 10;  // external variable (global)
int y = 20;  // external variable (global)

int main(void)
{
    printf("1️⃣ Global scope: x = %d, y = %d\n", x, y);

    // Example 1: simple block scope
    {
        int x = 1;  // hides global x
        printf("2️⃣ Inner block: x = %d (local hides global)\n", x);
    }

    printf("3️⃣ After inner block: x = %d (global again)\n", x);

    // Example 2: if block variable
    int n = 3;
    if (n > 0) {
        int i = 100;
        printf("4️⃣ Inside if: i = %d\n", i);
    }
    // i is not visible here
    // printf("%d", i); // would be an error

    // Example 3: for loop variable is local to loop
    for (int i = 0; i < 3; i++) {
        printf("5️⃣ for loop i = %d\n", i);
    }
    // i no longer exists here

    // Example 4: nested blocks
    {
        int a = 10;
        {
            int a = 20; // hides outer a
            printf("6️⃣ Nested inner a = %d\n", a);
        }
        printf("7️⃣ Outer a = %d\n", a);
    }

    // Example 5: variable shadowing function parameter (simulated)
    {
        double x = 3.14; // hides global int x
        printf("8️⃣ Local x hides global: x = %.2f\n", x);
    }

    // Example 6: block re-initialization each time
    for (int i = 0; i < 2; i++) {
        int counter = 0; // initialized fresh each iteration
        counter++;
        printf("9️⃣ Loop iteration %d, counter = %d\n", i, counter);
    }

    // Example 7: scope of declaration after compound statement
    {
        int z = 50;
        printf("🔟 z inside block = %d\n", z);
    }

    // Example 8: variable hiding global function name (rare but valid)
    {
        int printf = 42; // hides function name printf in this block
        // can't call printf() here safely
        (void)printf;    // just to use it
        puts("🧩 printf name hidden here");
    }

    // Example 9: automatic variables exist only within block
    {
        int temp = 123;
        printf("🧮 temp = %d (alive)\n", temp);
    }
    // printf("%d", temp); // would be an error

    // Example 10: nested blocks multiple levels
    {
        int a = 1;
        {
            int a = 2;
            {
                int a = 3;
                printf("🏁 Deepest level a = %d\n", a);
            }
            printf("🏁 Middle level a = %d\n", a);
        }
        printf("🏁 Outer level a = %d\n", a);
    }

    return 0;
}

