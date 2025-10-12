#include <stdio.h>

// Print first n Fibonacci numbers
void print_fib_sequence(int n)
{
    printf("First %d Fibonacci numbers:\n", n);

    if (n >= 1)
        printf("F(0) = 0\n");
    if (n >= 2)
        printf("F(1) = 1\n");

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        printf("F(%d) = %lld\n", i, c);
        a = b;
        b = c;
    }
}
