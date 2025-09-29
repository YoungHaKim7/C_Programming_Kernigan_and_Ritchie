#include <stdio.h>
#include <stdlib.h>

typedef enum types_tag {
    CHAR,
    INT,
    FLOAT
} types_t;

typedef struct store_tag {
    types_t type;
    void*   value;
} store_t;

void printValue(const store_t *o) {
    switch (o->type) {
    case CHAR:
        printf("%c\n", *(char*)(o->value));
        break;
    case INT:
        printf("%d\n", *(int*)(o->value));
        break;
    case FLOAT:
        printf("%.3f", *(float*)(o->value));
        break;
    default:
        exit(EXIT_FAILURE);
    }
    return;
}

int main() {
    store_t a;

    a.type = CHAR;
    a.value = malloc(1);
    *((char*) a.value) = 'A';
    printValue(&a);
    free(a.value);

    a.type = FLOAT;
    a.value = malloc(sizeof(float));
    *((float*) a.value) = 34.7;
    printValue(&a);
    free(a.value);

    return 0;
}
