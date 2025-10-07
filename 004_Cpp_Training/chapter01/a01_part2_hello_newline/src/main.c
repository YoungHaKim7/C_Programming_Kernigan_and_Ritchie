#include <stdio.h>

int main()
{
    printf("\xahello, ");
    printf("world");
    // escape letters 
    printf("\xa\xa");
    printf("world\xa");
}
