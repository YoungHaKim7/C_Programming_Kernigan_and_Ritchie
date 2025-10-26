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

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoints: add two points */
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
    struct rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

int main(void)
{
    printf("=== Section 6.2: Structures and Functions Examples ===\n\n");

    // Example 1: Using makepoint to initialize rectangle dynamically
    struct rect screen;
    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(10, 5);
    printf("1. Using makepoint: screen.pt1=(%d,%d), pt2=(%d,%d)\n",
        screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);

    // Example 2: Using makepoint to provide structure arguments to functions
    struct point middle;
    middle = makepoint(
        (screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);
    printf("2. Middle point using makepoint: (%d,%d)\n", middle.x, middle.y);

    // Example 3: Using addpoints to add two points
    struct point p1 = makepoint(3, 4);
    struct point p2 = makepoint(5, 6);
    struct point sum = addpoint(p1, p2);
    printf("3. Adding points (%d,%d) + (%d,%d) = (%d,%d)\n", p1.x, p1.y, p2.x,
        p2.y, sum.x, sum.y);

    // Example 4: Testing ptinrect function
    struct point test_point1 = makepoint(5, 2); // Inside
    struct point test_point2
        = makepoint(10, 5); // On boundary (should be false)
    struct point test_point3 = makepoint(11, 3); // Outside
    printf("4. Point testing:\n");
    printf("   Point (%d,%d) in rect? %s\n", test_point1.x, test_point1.y,
        ptinrect(test_point1, screen) ? "YES" : "NO");
    printf("   Point (%d,%d) in rect? %s\n", test_point2.x, test_point2.y,
        ptinrect(test_point2, screen) ? "YES" : "NO");
    printf("   Point (%d,%d) in rect? %s\n", test_point3.x, test_point3.y,
        ptinrect(test_point3, screen) ? "YES" : "NO");

    // Example 5: Using canonrect to normalize rectangle coordinates
    struct rect bad_rect;
    bad_rect.pt1 = makepoint(10, 8); // pt1 > pt2
    bad_rect.pt2 = makepoint(2, 3);
    printf("5. Before canonrect: pt1=(%d,%d), pt2=(%d,%d)\n", bad_rect.pt1.x,
        bad_rect.pt1.y, bad_rect.pt2.x, bad_rect.pt2.y);
    struct rect good_rect = canonrect(bad_rect);
    printf("   After canonrect: pt1=(%d,%d), pt2=(%d,%d)\n", good_rect.pt1.x,
        good_rect.pt1.y, good_rect.pt2.x, good_rect.pt2.y);

    // Example 6: Structure pointers and the -> operator
    struct point origin = makepoint(0, 0);
    struct point* pp = &origin;
    printf("6. Using -> operator: origin is (%d,%d)\n", pp->x, pp->y);
    printf("   Equivalent using (*pp).x: (%d,%d)\n", (*pp).x, (*pp).y);

    // Example 7: Rectangle with pointer
    struct rect r = { { 1, 1 }, { 5, 4 } };
    struct rect* rp = &r;
    printf("7. Rectangle pointer access:\n");
    printf("   r.pt1.x = %d, rp->pt1.x = %d\n", r.pt1.x, rp->pt1.x);
    printf("   (r.pt1).x = %d, (rp->pt1).x = %d\n", (r.pt1).x, (rp->pt1).x);

    // Example 8: Structure operator precedence examples
    struct str_info {
        int len;
        char* str;
    };

    struct str_info* p;
    struct str_info str_struct = { 5, "Hello" };

    p = &str_struct;
    printf("8. Operator precedence:\n");
    int original_len = p->len;
    printf("   ++p->len: %d (was %d)\n", ++(p->len), original_len);
    printf("   p->len: %d\n", p->len);

    // Example 9: More complex pointer operations
    char test_str[] = "World";
    str_struct.str = test_str;
    printf("9. String operations with structures:\n");
    printf("   *p->str = %c\n", *p->str);
    printf("   After *p->str++: str now points to '%s'\n", p->str);

    // Example 10: Structure copying and assignment
    struct rect rect1 = { { 0, 0 }, { 10, 10 } };
    struct rect rect2 = rect1; // Structure copy
    rect2.pt1 = makepoint(5, 5);
    printf("10. Structure operations:\n");
    printf("    rect1: (%d,%d) to (%d,%d), area = %d\n", rect1.pt1.x,
        rect1.pt1.y, rect1.pt2.x, rect1.pt2.y, area(rect1));
    printf("    rect2: (%d,%d) to (%d,%d), area = %d\n", rect2.pt1.x,
        rect2.pt1.y, rect2.pt2.x, rect2.pt2.y, area(rect2));

    // Example 11: Passing structures to functions
    printf("11. Function calls with structures:\n");
    printf("    Passing screen to area(): %d\n", area(screen));
    printf("    Returning structure from makepoint(7,9): (%d,%d)\n",
        makepoint(7, 9).x, makepoint(7, 9).y);

    // Example 12: Complex point calculations
    struct point vertices[] = { makepoint(0, 0), makepoint(4, 0),
        makepoint(4, 3), makepoint(0, 3) };
    struct point center_calc = makepoint(0, 0);
    for (int i = 0; i < 4; i++) {
        center_calc = addpoint(center_calc, vertices[i]);
    }
    center_calc = makepoint(center_calc.x / 4, center_calc.y / 4);
    printf("12. Polygon center calculation: (%d,%d)\n", center_calc.x,
        center_calc.y);

    printf("\n=== All examples completed successfully! ===\n");

    return 0;
}
