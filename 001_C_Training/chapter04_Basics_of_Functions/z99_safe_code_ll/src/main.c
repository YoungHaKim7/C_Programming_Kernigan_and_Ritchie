#include <stdio.h>

int main(void)
{
    int a = 1000 * 60 * 60 * 24; // may overflow 32-bit int
    long b = 1000L * 60L * 60L * 24L; // safe in long

    printf("int  version: %d\n", a);
    printf("long version: %ld\n", b);

    return 0;
}
