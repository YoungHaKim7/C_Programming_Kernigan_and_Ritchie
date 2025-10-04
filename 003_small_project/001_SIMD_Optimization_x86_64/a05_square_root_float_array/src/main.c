#include <math.h>
#include <stdio.h>
#include <xmmintrin.h>

int main()
{
    float a[4] = { 4, 9, 16, 25 };
    float result[4];
    __m128 va = _mm_loadu_ps(a);
    __m128 vr = _mm_sqrt_ps(va);
    _mm_storeu_ps(result, vr);
    for (int i = 0; i < 4; ++i)
        printf("%f ", result[i]);
    printf("\n");
    return 0;
}
