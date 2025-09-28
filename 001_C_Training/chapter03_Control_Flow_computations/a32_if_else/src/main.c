#include <stdio.h>

int main(void)
{
    int x = 10;
    x++;
    printf("x = 10\nx++\nx is now: %d\n", x);

    int n = 1;
    int a = 2;
    int b = 3;
    int z = 0;

    if (n > 0) {
        if (a > b) {
            z = a;
        } else {
            z = b;
        }
    }

    printf("z is: %d\n", z);

    return 0;
}