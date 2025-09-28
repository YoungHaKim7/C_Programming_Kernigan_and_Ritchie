#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Allocate space for 5 chars: "TEST" + '\0'
    char *buf = malloc(5);
    if (!buf) {
        perror("malloc failed");
        return 1;
    }

    // Copy string safely
    strcpy(buf, "TEST");

    // Now printf will stop correctly at '\0'
    printf("%s\n", buf);

    free(buf);
    return 0;
}
