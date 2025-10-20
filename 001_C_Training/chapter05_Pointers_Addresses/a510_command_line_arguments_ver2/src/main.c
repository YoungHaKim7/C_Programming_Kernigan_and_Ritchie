#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("Hello world C lang \n\n");

    while (--argc > 0) {
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
        printf("\n");
    }
    return 0;
}
