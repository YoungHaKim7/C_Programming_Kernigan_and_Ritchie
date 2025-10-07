#include <stdio.h>

int main()
{
    printf("Type some text (Ctrl+D to end):\n");

    double nc;

    for(nc = 0; getchar() != EOF; ++nc)
    {
        printf("%.0f\n", nc);
    }

    printf("\nDone!\n");

    return 0;
}
