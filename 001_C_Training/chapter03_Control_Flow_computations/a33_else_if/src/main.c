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
    printf("no match\n"); /* no match */
    return -1;
}

int main(void)
{
    int x_array[] = { 1, 4,  5, 6, 10, 11, 200, 400};
    int result = binsearch(20, x_array, 8);
    if (result == -1) {
        printf("No match found.\n");
    } else {
        printf("Found %d at index: %d\n", x_array[result], result);
    }

    int result02 = binsearch(5, x_array, 8);
    if (result02 == -1) {
        printf("No match found.\n");
    } else {
        printf("Found %d at index: %d\n", x_array[result02], result02);
    }

    return 0;
}
