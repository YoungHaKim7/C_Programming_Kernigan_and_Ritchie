#include <stdio.h>
#include <string.h>

// Trim trailing spaces, tabs, newlines
char* trim(char s[]) {
    int n;

    for (n = (int)strlen(s) - 1; n >= 0; n--) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') {
            break;
        }
    }
    s[n + 1] = '\0';
    return s;
}

int main(void)
{
    char test_str[] = "test \ttest\n  hello world\n\n\t\ntest\n\n";

    printf("Before trim: \"%s\"\n", test_str);
    printf("\n");
    printf("~~~~trim ()~~~");
    printf("\n");
    printf("After  trim: \"%s\"\n", trim(test_str));

    return 0;
}

