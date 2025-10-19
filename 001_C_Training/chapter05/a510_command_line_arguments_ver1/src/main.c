#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("Hello world C lang ");
    int i;

    for (i = 0; i < argc; i++) {
        printf("%s", argv[i]);
    }
    return 0;
}
