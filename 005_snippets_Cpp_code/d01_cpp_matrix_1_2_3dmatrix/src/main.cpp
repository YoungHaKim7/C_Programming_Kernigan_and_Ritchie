#include <iostream>
#include <vector>
#include <format>

int main()
{
    std::cout << "\n";
    std::cout << "1d array( 1d matrix)";
    std::cout << "\n";
    // 1D matrix
    int array_1dmatrix[] = { 1, 2, 3, 4, 5, 6 };
    int len = sizeof(array_1dmatrix) / sizeof(array_1dmatrix[0]);

    std::cout << "Matrix 1d: ";
    for (int i = 0; i < len; i++) {
        std::cout << std::format("{} ", array_1dmatrix[i]);
    }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~";
    std::cout << "2d array( 2d matrix)\n";


    // 2D matrix using std::vector
    int rows = 2, cols = 3;
    std::vector<std::vector<int>> matrix02(rows, std::vector<int>(cols));

    std::cout << std::format("Matrix ({}x{}) initialized with indices:\n", rows, cols);

    // Fill with row*col
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix02[i][j] = i * cols + j;
        }
    }

    // Print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::format("{:2} ", matrix02[i][j]);
        }
        std::cout << '\n';
    }

    // Another 3x3 zero matrix using std::vector
    int rows02 = 3, cols02 = 3;
    std::vector<std::vector<int>> matrix03(rows02, std::vector<int>(cols02, 0));

    std::cout << "\nMatrix 3x3 (all zeros):\n";
    for (int i = 0; i < rows02; i++) {
        for (int j = 0; j < cols02; j++) {
            std::cout << std::format("{:2} ", matrix03[i][j]);
        }
        std::cout << '\n';
    }

    // clang-format off
    // Proper 2D initializer
    int matrix04[2][3] = {
         { 0, 1, 2 },
         { 3, 4, 5 }
    };
    // clang-format on

    std::cout << "\nMatrix 2x3 (initializer):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << std::format("{:2} ", matrix04[i][j]);
        }
        std::cout << '\n';
    }

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~";
    std::cout << "3d array( 3d matrix)";
    std::cout << "\n";
    std::cout << "3d matrix sample";

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

    std::cout << "Matrix 3D (2x3x2):\n";

    for (int i = 0; i < 2; i++) {
        std::cout << std::format("Layer {}:\n", i);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                std::cout << std::format("{:2} ", matrix_3d_small[i][j][k]);
            }
            std::cout << '\n';
        }
        std::cout << '\n';
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

    std::cout << "Matrix 3D (5x3x2):\n";

    for (int i = 0; i < 5; i++) {
        std::cout << std::format("Layer {}:\n", i);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                std::cout << std::format("{:2} ", matrix_3d[i][j][k]);
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    return 0;
}
