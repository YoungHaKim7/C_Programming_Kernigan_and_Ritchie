#include <stdio.h>

int main(void)
{
    // make 1d matrix
    int array_1dmatrix[] = { 1, 2, 3, 4, 5, 6 };

    printf("Matrix 1d: (%d)", array_1dmatrix);

    // make 2d matrix init
    int rows = 2, cols = 3;
    int matrix02[rows][cols]; // VLA in C23

    printf("\n");
    printf("Matrix (%dx%d):\n", rows, cols);

    // make 2d matrix init
    int rows02 = 3, cols02 = 3;
    int matrix03[rows02][cols02]; // VLA in C23

    // Fill with 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix03[i][j] = 0;
        }
    }

    // Print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix02[i][j]);
        }
        putchar('\n');
    }

    // 2d matrix
    // clang-format off
    int matrix04[2][3] = {
        {0,1}, {2,3,}, {4,5},
        {1,2}, {3,4,}, {5,6},
    };
    // clang-format on

    // Print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix04[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
