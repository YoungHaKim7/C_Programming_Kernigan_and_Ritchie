#include <stdio.h>

int main(void)
{
    // 1D matrix
    int array_1dmatrix[] = { 1, 2, 3, 4, 5, 6 };
    int len = sizeof(array_1dmatrix) / sizeof(array_1dmatrix[0]);

    printf("Matrix 1d: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", array_1dmatrix[i]);
    }
    printf("\n");
    printf("\n");

    // 2D matrix init (VLA in C23)
    int rows = 2, cols = 3;
    int matrix02[rows][cols];

    printf("Matrix (%dx%d) initialized with indices:\n", rows, cols);

    // Fill with row*col
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix02[i][j] = i * cols + j;
        }
    }

    // Print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix02[i][j]);
        }
        putchar('\n');
    }

    // Another 3x3 zero matrix
    int rows02 = 3, cols02 = 3;
    int matrix03[rows02][cols02];

    for (int i = 0; i < rows02; i++) {
        for (int j = 0; j < cols02; j++) {
            matrix03[i][j] = 0;
        }
    }

    printf("\nMatrix 3x3 (all zeros):\n");
    for (int i = 0; i < rows02; i++) {
        for (int j = 0; j < cols02; j++) {
            printf("%2d ", matrix03[i][j]);
        }
        putchar('\n');
    }

    // clang-format off
    // Proper 2D initializer
    int matrix04[2][3] = {
         { 0, 1, 2 },
         { 3, 4, 5 }
    };
    // clang-format on

    printf("\nMatrix 2x3 (initializer):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d ", matrix04[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
