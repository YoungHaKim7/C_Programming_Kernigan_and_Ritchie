#include <stdio.h>

int main(void)
{
    // Example 1: Conditional expression for assigning a maximum value
    int a = 20;
    int b = 10;
    int z;

    // Using if-else statement
    if (a > b)
        z = a;
    else
        z = b;
    printf("Example 1 (if-else): z = %d\n", z);

    // Using conditional expression (ternary operator)
    z = (a > b) ? a : b;
    printf("Example 1 (ternary): z = %d\n\n", z);


    // Example 2: Printing an array with conditional formatting
    int n = 25;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Example 2: Printing an array with special formatting\n");
    for (int i = 0; i < n; i++)
        printf("%6d%c", arr[i], (i%10==9 || i==n-1) ? '\n' : ' ');
    printf("\n");


    // Example 3: Conditional pluralization in printf
    int items1 = 1;
    int items2 = 5;

    printf("Example 3: Conditional pluralization\n");
    printf("You have %d item%s.\n", items1, items1==1 ? "" : "s");
    printf("You have %d item%s.\n", items2, items2==1 ? "" : "s");

    return 0;
}