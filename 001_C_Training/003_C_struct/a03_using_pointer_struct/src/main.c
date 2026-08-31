#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

void move_point(Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

int main(void) {
    Point point = {10, 20};

    printf("Before: (%d, %d)\n", point.x, point.y);

    // Pass the address of point
    move_point(&point, 5, 10);

    printf("After:  (%d, %d)\n", point.x, point.y);

    return 0;
}
