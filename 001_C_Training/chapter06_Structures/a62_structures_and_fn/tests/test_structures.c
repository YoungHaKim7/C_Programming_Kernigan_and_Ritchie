/* Test file for Section 6.2 Structures and Functions */
#include <assert.h>
#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

/* Function implementations */
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct rect canonrect(struct rect r)
{
    struct rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}

int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

int main(void)
{
    printf("=== Testing Section 6.2 Functions ===\n\n");

    // Test 1: makepoint function
    printf("Test 1: makepoint function\n");
    struct point p1 = makepoint(3, 4);
    struct point p2 = makepoint(0, 0);
    assert(p1.x == 3 && p1.y == 4);
    assert(p2.x == 0 && p2.y == 0);
    printf("  ✓ makepoint works correctly\n");

    // Test 2: addpoints function
    printf("Test 2: addpoints function\n");
    struct point sum = addpoint(p1, p2);
    assert(sum.x == 3 && sum.y == 4);
    sum = addpoint(makepoint(5, 6), makepoint(2, 3));
    assert(sum.x == 7 && sum.y == 9);
    printf("  ✓ addpoints works correctly\n");

    // Test 3: canonrect function
    printf("Test 3: canonrect function\n");
    struct rect bad = { { 10, 8 }, { 2, 3 } };
    struct rect good = canonrect(bad);
    assert(good.pt1.x == 2 && good.pt1.y == 3);
    assert(good.pt2.x == 10 && good.pt2.y == 8);
    printf("  ✓ canonrect works correctly\n");

    // Test 4: ptinrect function
    printf("Test 4: ptinrect function\n");
    struct rect test_rect = { { 0, 0 }, { 10, 5 } };
    assert(ptinrect(makepoint(5, 2), test_rect) == 1); // Inside
    assert(ptinrect(makepoint(9, 4), test_rect) == 1); // Inside
    assert(ptinrect(makepoint(10, 5), test_rect) == 0); // On boundary
    assert(ptinrect(makepoint(11, 3), test_rect) == 0); // Outside
    assert(ptinrect(makepoint(5, 5), test_rect) == 0); // On boundary
    printf("  ✓ ptinrect works correctly\n");

    // Test 5: Complex operations
    printf("Test 5: Complex operations\n");
    struct rect screen = { makepoint(0, 0), makepoint(20, 10) };
    struct point center = makepoint(
        (screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);
    assert(center.x == 10 && center.y == 5);
    printf("  ✓ Complex operations work correctly\n");

    // Test 6: Pointer operations
    printf("Test 6: Pointer operations\n");
    struct point origin = makepoint(0, 0);
    struct point* pp = &origin;
    assert(pp->x == 0 && pp->y == 0);
    assert((*pp).x == 0 && (*pp).y == 0);
    printf("  ✓ Pointer operations work correctly\n");

    printf("\n=== All tests passed! ===\n");
    return 0;
}