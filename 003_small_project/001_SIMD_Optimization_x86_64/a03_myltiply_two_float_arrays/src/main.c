#include <immintrin.h>
#include <stdio.h>

int main()
{
    float a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    float b[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
    float result[8];
    __m256 va = _mm256_loadu_ps(a);
    __m256 vb = _mm256_loadu_ps(b);
    __m256 vr = _mm256_mul_ps(va, vb);
    _mm256_storeu_ps(result, vr);
    int len = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < len; ++i)
        printf("%f ", result[i]);
    printf("\n");
    return 0;
}
