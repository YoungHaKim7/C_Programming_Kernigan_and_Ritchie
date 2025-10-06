#include <assert.h>
#include <stdio.h>
#include <xmmintrin.h>

int main(void)
{

    // 4x4 matrices
    // clang-format off
    float a[4][4] = {
        { 1,  2,  3,  4 },
        { 5,  6,  7,  8 },
        { 9, 10, 11, 12 },
        {13, 14, 15, 16 }
    };

    float b[4][4] = {
        {16, 15, 14, 13 },
        {12, 11, 10,  9 },
        { 8,  7,  6,  5 },
        { 4,  3,  2,  1 }
    };
    // clang-format on

    float result[4][4];

    int len = sizeof(a) / sizeof(a[0]);
    int len2 = sizeof(b) / sizeof(b[0]);
    assert(len == len2);

    // Add the matrices row by row using SSE
    for (int i = 0; i < len; ++i) {
        __m128 va = _mm_loadu_ps(a[i]); // load 4 floats from row i of A
        __m128 vb = _mm_loadu_ps(b[i]); // load 4 floats from row i of B
        __m128 vr = _mm_add_ps(va, vb); // element-wise add
        _mm_storeu_ps(result[i], vr); // store result into row i
    }

    printf("Matrix result (A + B):\n");
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            printf("%6.1f ", result[i][j]);
        putchar('\n');
    }

    return 0;
}
