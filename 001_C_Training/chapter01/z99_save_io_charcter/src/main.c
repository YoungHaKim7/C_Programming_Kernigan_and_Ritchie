#include <stdio.h>

int main(void)
{
    printf("Type some text (Ctrl+D to end):\n");

    FILE *out = fopen("output.txt", "w"); // open file for writing
    if (!out) {
        perror("output.txt");
        return 1;
    }

    int ch;

    while ((ch = getchar()) != EOF) {
        fputc(ch, out);   // write the character itself
    }

    fclose(out);

    printf("\nDone! Saved input text to output.txt\n");
    return 0;
}
