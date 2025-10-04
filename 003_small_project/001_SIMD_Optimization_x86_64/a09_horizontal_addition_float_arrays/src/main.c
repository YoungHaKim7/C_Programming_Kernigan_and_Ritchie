#include <stdio.h>
#include <pmmintrin.h>

int main() {
    float a[4] = {1.0, 2.0, 3.0, 4.0};
    __m128 va = _mm_loadu_ps(a);
    __m128 sum = _mm_hadd_ps(va, va);
    float result[4];
    _mm_storeu_ps(result, sum);
    for (int i = 0; i < 4; ++i) printf("%f ", result[i]);
    printf("\n");
    return 0;
}
