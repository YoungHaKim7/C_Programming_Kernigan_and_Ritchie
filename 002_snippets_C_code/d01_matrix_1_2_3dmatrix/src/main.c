#include <stdio.h>

int main(void)
{
    printf("\n");
    printf("1d array( 1d matrix)");
    printf("\n");
    // 1D matrix
    int array_1dmatrix[] = { 1, 2, 3, 4, 5, 6 };
    int len = sizeof(array_1dmatrix) / sizeof(array_1dmatrix[0]);

    printf("Matrix 1d: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", array_1dmatrix[i]);
    }
    printf("\n");
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~");
    printf("2d array( 2d matrix)\n");


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

    printf("\n");
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~");
    printf("3d array( 3d matrix)");
    printf("\n");
    printf("3d matrix sample");

    // clang-format off
    // 3D matrix [2][3][2]
    // 2 layers, 3 rows per layer, 2 columns per row
    int matrix_3d[2][3][2] = {
        {
            {0, 1},
            {2, 3},
            {4, 5}
        },   // layer 0
        {
            {6, 7},
            {8, 9},
            {10, 11}
        }  // layer 1
    };
    // clang-format on

    printf("Matrix 3D (2x3x2):\n");

    for (int i = 0; i < 2; i++) {
        printf("Layer %d:\n", i);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                printf("%2d ", matrix_3d[i][j][k]);
            }
            putchar('\n');
        }
        putchar('\n');
    }

    return 0;
}
