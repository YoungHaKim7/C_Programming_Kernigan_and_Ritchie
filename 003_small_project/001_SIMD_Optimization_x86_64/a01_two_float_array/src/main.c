#include <stdio.h>
#include <xmmintrin.h>

int main()
{
    float a[4] = { 1, 2, 3, 4 };
    float b[4] = { 5, 6, 7, 8 };
    float result[4];
    __m128 va = _mm_loadu_ps(a);
    __m128 vb = _mm_loadu_ps(b);
    __m128 vr = _mm_add_ps(va, vb);
    _mm_storeu_ps(result, vr);
    for (int i = 0; i < 4; ++i)
        printf("%f ", result[i]);
    printf("\n");
    return 0;
}
