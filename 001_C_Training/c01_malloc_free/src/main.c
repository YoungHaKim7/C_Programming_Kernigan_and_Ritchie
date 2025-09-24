#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* ptr = malloc(sizeof(int));
    *ptr = 42;
    printf("ptr : %p", &ptr);
    free(ptr);
    return 0;
    
    // error
    // int* ptr = malloc(sizeof(int));
    // printf("ptr : %p", &ptr);
    // free(ptr);
    // *ptr = 42;
}
