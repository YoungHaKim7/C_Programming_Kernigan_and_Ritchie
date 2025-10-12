#include <stdio.h>
/* printd: print n in decimal */
void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return;
    /* fewer than two elements */
    swap(v, left, (left + right) / 2); /* move partition elem */
    last = left;
    /* to v[0] */
    for (i = left + 1; i <= right; i++) /* partition */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    /* restore partition elem */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main()
{
    printf("Example 1: Printing positive number 123\n");
    printd(123);
    printf("\n");

    printf("Example 2: Printing negative number -456\n");
    printd(-456);
    printf("\n");

    printf("Example 3: Printing zero\n");
    printd(0);
    printf("\n");

    printf("Example 4: Printing single digit 7\n");
    printd(7);
    printf("\n");

    printf("Example 5: Sorting array [3, 1, 4, 1, 5]\n");
    int arr1[] = {3, 1, 4, 1, 5};
    qsort(arr1, 0, 4);
    for(int i = 0; i < 5; i++) printf("%d ", arr1[i]);
    printf("\n");

    printf("Example 6: Sorting array [9, 8, 7, 6, 5]\n");
    int arr2[] = {9, 8, 7, 6, 5};
    qsort(arr2, 0, 4);
    for(int i = 0; i < 5; i++) printf("%d ", arr2[i]);
    printf("\n");

    printf("Example 7: Sorting array [1, 2, 3, 4, 5]\n");
    int arr3[] = {1, 2, 3, 4, 5};
    qsort(arr3, 0, 4);
    for(int i = 0; i < 5; i++) printf("%d ", arr3[i]);
    printf("\n");

    printf("Example 8: Sorting array [5, -1, 3, -2, 0]\n");
    int arr4[] = {5, -1, 3, -2, 0};
    qsort(arr4, 0, 4);
    for(int i = 0; i < 5; i++) printf("%d ", arr4[i]);
    printf("\n");

    printf("Example 9: Printing large number 99999\n");
    printd(99999);
    printf("\n");

    printf("Example 10: Sorting single element array [42]\n");
    int arr5[] = {42};
    qsort(arr5, 0, 0);
    printf("%d\n", arr5[0]);

    return 0;
}
