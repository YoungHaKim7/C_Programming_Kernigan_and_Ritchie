#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // good malloc & free
    // int* ptr = malloc(sizeof(int));
    // *ptr = 42;
    // printf("ptr : %p", &ptr);
    // free(ptr);
    // return 0;

    // error code(ERROR: AddressSanitizer: heap-use-after-free)
    int* ptr = malloc(sizeof(int));
    printf("ptr : %p", &ptr);
    free(ptr);
    *ptr = 42;
    return 0;
}
