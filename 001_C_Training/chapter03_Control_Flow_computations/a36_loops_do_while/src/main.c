#include <stdio.h>
#include <string.h>

// reverse string in place
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = (int)strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// convert int -> string
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) // check sign
        n = -n;         // make n positive

    i = 0;
    do {
        s[i++] = n % 10 + '0';  // get next digit
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    char buf[50];

    // Reverse test
    char test_string[] = "Hello, World!";
    printf("Original string: %s\n", test_string);
    reverse(test_string);
    printf("Reversed string: %s\n", test_string);

    // itoa tests
    itoa(123, buf);
    printf("itoa(123)  = %s\n", buf);

    itoa(-456, buf);
    printf("itoa(-456) = %s\n", buf);

    itoa(0, buf);
    printf("itoa(0)    = %s\n", buf);

    itoa(7890, buf);
    printf("itoa(7890) = %s\n", buf);

    itoa(-2147483648LL, buf); // edge case for 32-bit int
    printf("itoa(INT_MIN) = %s\n", buf);

    printf("\nDone!\n");
    return 0;
}
