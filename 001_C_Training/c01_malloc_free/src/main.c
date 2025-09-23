#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* ptr = malloc(sizeof(int));
    *ptr = 42;
    printf("ptr : %p", &ptr);
    free(ptr);
    // error
    return 0;
}
