#include <stdfil.h>
#include <stdlib.h>

int main()
{
    char* p = malloc(16);
    zprintf("p = %P\n", p + 42);
    return 0;
}
