#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main(void)
{
    // Array indexing: a[b]
    int arr[5] = { 10, 20, 30, 40, 50 };
    int index = 2;
    printf("arr[%d] = %d\n", index, arr[index]);

    // Pointer dereference: *a
    int value = 100;
    int* ptr = &value;
    printf("*ptr = %d (value at the address stored in ptr)\n", *ptr);

    // Address-of: &a
    printf("&value = %p (address of value)\n", (void*)&value);

    // Structure member access: a.b
    struct Point p1;
    p1.x = 5;
    p1.y = 10;
    printf("p1.x = %d, p1.y = %d (using a.b)\n", p1.x, p1.y);

    // Structure pointer member access: a->b
    struct Point* p2 = &p1;
    printf("p2->x = %d, p2->y = %d (using a->b)\n", p2->x, p2->y);

    return 0;
}
