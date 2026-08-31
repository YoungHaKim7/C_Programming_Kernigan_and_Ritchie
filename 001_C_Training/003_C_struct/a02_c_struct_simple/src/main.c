#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int main(void) {
    Point point = {10, 20};

    printf("x = %d\n", point.x);
    printf("y = %d\n", point.y);

    return 0;
}
