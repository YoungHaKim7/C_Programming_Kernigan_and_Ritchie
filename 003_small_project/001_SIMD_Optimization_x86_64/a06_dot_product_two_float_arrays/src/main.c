#include <stdio.h>
#include <xmmintrin.h>

int main()
{
    float a[4] = { 1, 2, 3, 4 }, b[4] = { 4, 3, 2, 1 };
    __m128 va = _mm_loadu_ps(a);
    __m128 vb = _mm_loadu_ps(b);
    __m128 vmul = _mm_mul_ps(va, vb);
    float res[4];
    _mm_storeu_ps(res, vmul);
    float dot = res[0] + res[1] + res[2] + res[3];
    printf("Dot product: %f\n", dot);
    return 0;
}
