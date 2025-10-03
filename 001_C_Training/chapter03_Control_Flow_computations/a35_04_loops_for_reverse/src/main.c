#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) -1; i < j; i++, j--)
    {
        c = s [i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main(void)
{
    char test_string[] = "Hello, World!";
    
    printf("Original string: %s\n", test_string);
    reverse(test_string);
    printf("Reversed string: %s\n", test_string);
    
    printf("\nDone!\n");
    return 0;
}
