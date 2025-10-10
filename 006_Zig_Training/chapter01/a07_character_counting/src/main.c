#include <stdio.h>

int main(void)
{
    printf("Type some text (Ctrl+D to end):\n");

    long nc;

    nc = 0;

    while (getchar() != EOF) {

        ++nc;
        printf("%ld\n", nc);
    }

    printf("\nDone!\n");

    return 0;
}
