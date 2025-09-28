#include <stdio.h>
#include <ctype.h>

// atoi: int atoi(char s[]) convert s to integer; version 2
int atoi_v2(char s[]) {
    int i, n = 0, sign;
    for (i = 0; isspace((unsigned char)s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (; isdigit((unsigned char)s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

// shellsort: sort v[0]...v[n-1] into increasing order
void shellsort(int v[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}

void print_array(const char *msg, int v[], int n) {
    printf("%s", msg);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(void) {
    // --- atoi tests ---
    char *tests[] = {
        "123", "-456", "   789", "+42", "00099",
        "  -0010", "2147483647", "-2147483648",
        "  +0000123", "999999999"
    };

    printf("=== ATOI TESTS ===\n");
    for (int i = 0; i < 10; i++) {
        int val = atoi_v2(tests[i]);
        printf("[%d] '%s' => %d\n", i, tests[i], val);
    }

    // --- shellsort tests ---
    printf("\n=== SHELLSORT TESTS ===\n");

    int arr1[] = {5, 2, 9, 1, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    shellsort(arr1, n1);
    print_array("[arr1 sorted] ", arr1, n1);

    int arr2[] = {10, 9, 8, 7, 6, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    shellsort(arr2, n2);
    print_array("[arr2 sorted] ", arr2, n2);

    int arr3[] = {1, 2, 3, 4, 5, 6};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    shellsort(arr3, n3);
    print_array("[arr3 sorted] ", arr3, n3);

    int arr4[] = {42};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    shellsort(arr4, n4);
    print_array("[arr4 sorted] ", arr4, n4);

    int arr5[] = {3, -1, 0, -7, 2};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    shellsort(arr5, n5);
    print_array("[arr5 sorted] ", arr5, n5);

    return 0;
}
