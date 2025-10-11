#include <stdio.h>

int main(void)
{
    // 'register' suggests these variables are frequently used.
    register int sum = 0;
    register int i;

    // Sum the first 10 natural numbers.
    for (i = 1; i <= 10; ++i) {
        sum += i;
    }

    printf("Sum of first 10 numbers = %d\n", sum);

    // Another example with char
    register char c;

    printf("Enter a character: ");
    c = getchar();  // read one character from stdin

    printf("You entered: %c\n", c);

    // Example of register variable inside a function scope
    {
        register int count = 5;
        while (count--) {
            printf("Countdown: %d\n", count);
        }
    }

    return 0;
}
