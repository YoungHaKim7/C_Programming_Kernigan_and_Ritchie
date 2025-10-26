#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

// Function to compute width and height
int width(struct rect r) { return r.pt2.x - r.pt1.x; }

int height(struct rect r) { return r.pt2.y - r.pt1.y; }

int area(struct rect r) { return width(r) * height(r); }

int main(void)
{
    struct rect screen;

    // Example 1: Initialize both points
    screen.pt1.x = 0;
    screen.pt1.y = 0;
    screen.pt2.x = 10;
    screen.pt2.y = 5;
    printf("1. screen.pt1=(%d,%d), pt2=(%d,%d)\n", screen.pt1.x, screen.pt1.y,
        screen.pt2.x, screen.pt2.y);

    // Example 2: Compute width
    printf("2. width = %d\n", width(screen));

    // Example 3: Compute height
    printf("3. height = %d\n", height(screen));

    // Example 4: Compute area
    printf("4. area = %d\n", area(screen));

    // Example 5: Move rectangle by (+5, +5)
    screen.pt1.x += 5;
    screen.pt1.y += 5;
    screen.pt2.x += 5;
    screen.pt2.y += 5;
    printf("5. moved rect: pt1=(%d,%d), pt2=(%d,%d)\n", screen.pt1.x,
        screen.pt1.y, screen.pt2.x, screen.pt2.y);

    // Example 6: Scale rectangle (double width and height)
    int w = width(screen);
    int h = height(screen);
    screen.pt2.x = screen.pt1.x + 2 * w;
    screen.pt2.y = screen.pt1.y + 2 * h;
    printf("6. scaled rect: pt1=(%d,%d), pt2=(%d,%d)\n", screen.pt1.x,
        screen.pt1.y, screen.pt2.x, screen.pt2.y);

    // Example 7: Check if point is inside
    struct point p = { 12, 8 };
    int inside = (p.x >= screen.pt1.x && p.x <= screen.pt2.x
        && p.y >= screen.pt1.y && p.y <= screen.pt2.y);
    printf("7. point (%d,%d) inside? %s\n", p.x, p.y, inside ? "yes" : "no");

    // Example 8: Calculate center point
    struct point center;
    center.x = (screen.pt1.x + screen.pt2.x) / 2;
    center.y = (screen.pt1.y + screen.pt2.y) / 2;
    printf("8. center = (%d,%d)\n", center.x, center.y);

    // Example 9: Make a square using same struct
    struct rect square = { { 0, 0 }, { 4, 4 } };
    printf("9. square area = %d\n", area(square));

    // Example 10: Rect with negative coordinates
    struct rect neg = { { -5, -5 }, { 5, 5 } };
    printf("10. rect with negatives area = %d\n", area(neg));

    return 0;
}
