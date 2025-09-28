#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Allocate space for 4 chars (but no room for the '\0')
    char *buf = malloc(4);
    buf[0] = 'T';
    buf[1] = 'E';
    buf[2] = 'S';
    buf[3] = 'T';  // <- No null terminator inside allocated memory

    // printf will keep reading until it finds a '\0' (past the buffer)
    printf("%s\n", buf);

    free(buf);
    return 0;
}
