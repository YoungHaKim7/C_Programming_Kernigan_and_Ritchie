#include <stdio.h>

// Function prototypes
long long fib_recursive(int n);
long long fib_iterative(int n);
long long fib_optimized(int n);
void print_fib_sequence(int n);

int main(void)
{
    int n;
    int choice;

    printf("Fibonacci Sequence Calculator\n");
    printf("----------------------------\n");
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: Please enter a non-negative number.\n");
        return 1;
    }

    printf("\nChoose calculation method:\n");
    printf("1. Recursive (inefficient for large n)\n");
    printf("2. Iterative (recommended)\n");
    printf("3. Optimized (space-efficient)\n");
    printf("4. Print entire sequence\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        if (n > 40) {
            printf("Warning: Recursive method is very slow for n > 40!\n");
            printf("Consider using iterative method instead.\n");
        }
        printf("Fibonacci number F(%d) = %lld\n", n, fib_recursive(n));
        break;
    case 2:
        printf("Fibonacci number F(%d) = %lld\n", n, fib_iterative(n));
        break;
    case 3:
        printf("Fibonacci number F(%d) = %lld\n", n, fib_optimized(n));
        break;
    case 4:
        print_fib_sequence(n);
        break;
    default:
        printf("Invalid choice. Using iterative method.\n");
        printf("Fibonacci number F(%d) = %lld\n", n, fib_iterative(n));
    }

    return 0;
}

// Recursive Fibonacci (inefficient - O(2^n))
long long fib_recursive(int n)
{
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Iterative Fibonacci (efficient - O(n))
long long fib_iterative(int n)
{
    if (n <= 1)
        return n;

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Optimized Fibonacci (space-efficient - O(1) space)
long long fib_optimized(int n)
{
    if (n <= 1)
        return n;

    long long prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        curr = prev + curr;
        prev = curr - prev;
    }
    return curr;
}

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
