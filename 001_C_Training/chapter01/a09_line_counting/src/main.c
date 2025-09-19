#include <stdio.h>

int main(void)
{
    printf("Type some text (Ctrl+D to end):\n");

    int c, nl;

    nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        printf("%d\n", nl);
    }

    printf("\nDone!\n");

    return 0;
}
