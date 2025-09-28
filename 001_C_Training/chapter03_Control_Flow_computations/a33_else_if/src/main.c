#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

int main(void)
{
    int x_array[] = { 1, 4,  5, 6, 10, 11, 200, 400};
    int result = binsearch(20, x_array, 8);
    printf("Found 20 at index: %d\n", result);

    return 0;
}
