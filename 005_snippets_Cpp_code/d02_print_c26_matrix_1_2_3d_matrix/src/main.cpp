#include <format>
#include <print>
#include <vector>

int main()
{
    std::println("");
    std::println("1d array( 1d matrix)");
    std::println("");
    // 1D matrix
    int array_1dmatrix[] = { 1, 2, 3, 4, 5, 6 };
    int len = sizeof(array_1dmatrix) / sizeof(array_1dmatrix[0]);

    std::print("Matrix 1d: ");
    for (int i = 0; i < len; i++) {
        std::print("{} ", array_1dmatrix[i]);
    }
    std::println("");
    std::println("");
    std::print("~~~~~~~~~~~~~~~~~~~");
    std::println("2d array( 2d matrix)");

    // 2D matrix using std::vector
    int rows = 2, cols = 3;
    std::vector<std::vector<int>> matrix02(rows, std::vector<int>(cols));

    std::println("Matrix ({}x{}) initialized with indices:", rows, cols);

    // Fill with row*col
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix02[i][j] = i * cols + j;
        }
    }

    // Print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::print("{:2} ", matrix02[i][j]);
        }
        std::println("");
    }

    // Another 3x3 zero matrix using std::vector
    int rows02 = 3, cols02 = 3;
    std::vector<std::vector<int>> matrix03(rows02, std::vector<int>(cols02, 0));

    std::println("");
    std::println("Matrix 3x3 (all zeros):");
    for (int i = 0; i < rows02; i++) {
        for (int j = 0; j < cols02; j++) {
            std::print("{:2} ", matrix03[i][j]);
        }
        std::println("");
    }

    // clang-format off
    // Proper 2D initializer
    int matrix04[2][3] = {
         { 0, 1, 2 },
         { 3, 4, 5 }
    };
    // clang-format on

    std::println("");
    std::println("Matrix 2x3 (initializer):");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::print("{:2} ", matrix04[i][j]);
        }
        std::println("");
    }

    std::println("");
    std::println("");
    std::print("~~~~~~~~~~~~~~~~~~~");
    std::println("3d array( 3d matrix)");
    std::println("");
    std::println("3d matrix sample");

    // clang-format off
    // 3D matrix [2][3][2]
    // 2 layers, 3 rows per layer, 2 columns per row
    int matrix_3d_small[2][3][2] = {
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

    std::println("Matrix 3D (2x3x2):");

    for (int i = 0; i < 2; i++) {
        std::println("Layer {}:", i);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                std::print("{:2} ", matrix_3d_small[i][j][k]);
            }
            std::println("");
        }
        std::println("");
    }

    // clang-format off
    // 3D matrix [5][3][2]
    // 5 layers, 3 rows per layer, 2 columns per row
    int matrix_3d[5][3][2] = {
        {   // Layer 0
            {  0,  1 },
            {  2,  3 },
            {  4,  5 }
        },
        {   // Layer 1
            {  6,  7 },
            {  8,  9 },
            { 10, 11 }
        },
        {   // Layer 2
            { 12, 13 },
            { 14, 15 },
            { 16, 17 }
        },
        {   // Layer 3
            { 18, 19 },
            { 20, 21 },
            { 22, 23 }
        },
        {   // Layer 4
            { 24, 25 },
            { 26, 27 },
            { 28, 29 }
        }
    };
    // clang-format on

    std::println("Matrix 3D (5x3x2):");

    for (int i = 0; i < 5; i++) {
        std::println("Layer {}:", i);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                std::print("{:2} ", matrix_3d[i][j][k]);
            }
            std::println("");
        }
        std::println("");
    }

    return 0;
}
