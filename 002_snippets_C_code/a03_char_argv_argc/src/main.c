#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("Hello world C lang\n char* argv[] style \n\n");
    int i;

    for (i = 0; i < argc; i++) {
        printf("argv[%d]:  %s\n", i, argv[i]);
    }

    return 0;
}
