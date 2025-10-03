#include <stdio.h>

int main(void)
{
    int a[] = { 1, 3, 5, 7, 9 };
    int b[] = { 2, 4, 6, 8, 9 }; // 9 is common
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                goto found; // jump to found label
            }
        }
    }

    // If we finish loops without goto, no common element
    printf("No common element found.\n");

found:
    printf("Found common element: %d (a[%d] == b[%d])\n", a[i], i, j);
    return 0;
}
