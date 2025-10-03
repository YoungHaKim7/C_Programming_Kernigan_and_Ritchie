#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */

int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;   // found at index i
    }
    return -1; // not found
}

int main(void)
{
    char line[MAXLINE] =
        "Ah Love! could you and I with Fate conspire "
        "To grasp this sorry Scheme of Things entire, "
        "Would not we shatter it to bits -- and then "
        "Re-mould it nearer to the Heart's Desire!";

    int found = 0;

    if (strindex(line, pattern) >= 0) {
        printf("%s\n", line);
        found++;
    }

    printf("Found count = %d\n", found);
    return found;
}
