#include "headers/common.h"

void copy(void) {
    int i = 0;
    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}
