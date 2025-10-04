#include <smmintrin.h>
#include <stdio.h>

int main()
{
    float a[4] = { 1, 2, 3, 4 }, b[4] = { 5, 6, 7, 8 }, result[4];
    __m128 va = _mm_loadu_ps(a);
    __m128 vb = _mm_loadu_ps(b);
    __m128 vr = _mm_blend_ps(va, vb, 0b1010);
    _mm_storeu_ps(result, vr);
    int len = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < len; ++i)
        printf("%f ", result[i]);
    printf("\n");
    return 0;
}
