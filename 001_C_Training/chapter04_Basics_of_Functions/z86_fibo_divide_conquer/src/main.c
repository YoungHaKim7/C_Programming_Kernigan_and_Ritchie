#include "./fib_iterative.c"
#include "./fib_optimized.c"
#include "./fib_recursive.c"
#include "./headers/common.h"
#include "./print_fib_sequence.c"

#include <stdio.h>

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
