#include <stdio.h>

int main()
{
    int num = 5;

    int *p1, *p2;

    p1 = &num;
    p2 = &num;

    printf("sizeof(int) : %zu\n", sizeof(int));
    printf("sizeof(int*) : %zu\n", sizeof(int*));

    printf("sizeof(p1) : %zu\n", sizeof(p1));
    printf("sizeof(p2) : %zu\n", sizeof(p2));

    printf("*p1: %d\n", *p1);
    // printf("*p2: %d\n", *p2);
}
