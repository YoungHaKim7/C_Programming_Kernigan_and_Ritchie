#include <stdio.h>

int main(void)
{
    printf("=== Pointer & and * Operator Examples ===\n\n");

    int x = 1, y = 2, z[10];
    int* ip; // ip is a pointer to int

    printf("Initial values: x=%d, y=%d\n\n", x, y);

    // 1️⃣ Assign address of x to pointer ip
    ip = &x; // ip points to x
    printf("ip = &x;  // ip now points to x\n");
    printf("Address of x: %p\n", (void*)&x);
    printf("Value of ip : %p\n", (void*)ip);
    printf("*ip (value at ip) = %d\n\n", *ip);

    // 2️⃣ Copy the value pointed to by ip into y
    y = *ip; // dereference ip
    printf("y = *ip;  // y is now %d (same as x)\n", y);

    // 3️⃣ Change the value of x through the pointer
    *ip = 0; // sets x to 0
    printf("*ip = 0;  // x is now %d\n\n", x);

    // 4️⃣ Make ip point to first element of array z
    ip = &z[0];
    z[0] = 99;
    printf("ip = &z[0];  // ip now points to z[0]\n");
    printf("Address of z[0]: %p\n", (void*)&z[0]);
    printf("Value of *ip (z[0]) = %d\n\n", *ip);

    // 5️⃣ Demonstrate pointer arithmetic
    z[1] = 77;
    ip = z; // same as &z[0]
    *(ip + 1) = 55; // sets z[1] = 55
    printf("*(ip + 1) = 55;  // z[1] changed to %d\n", z[1]);

    // 6️⃣ Pointer assignment to another pointer
    int* jp = ip;
    *jp = 123; // same as z[0] = 123
    printf("*jp = 123;  // z[0] = %d\n\n", z[0]);

    // 7️⃣ Show that & cannot apply to constants or expressions
    // int *bad = &10;        // ❌ Error: cannot take address of constant
    // int *bad2 = &(x + y);  // ❌ Error: cannot take address of expression

    // 8️⃣ Register variables cannot have their address taken
    register int r = 5;
    // int *rp = &r;          // ❌ Error: cannot take address of register variable

    // 9️⃣ Print final summary
    printf("Final values:\n");
    printf("x=%d, y=%d, z[0]=%d, z[1]=%d\n", x, y, z[0], z[1]);
    printf("ip points to %p (value=%d)\n", (void*)ip, *ip);
    printf("jp points to %p (value=%d)\n", (void*)jp, *jp);

    printf("\n=== End of Pointer Example ===\n");

    return 0;
}
