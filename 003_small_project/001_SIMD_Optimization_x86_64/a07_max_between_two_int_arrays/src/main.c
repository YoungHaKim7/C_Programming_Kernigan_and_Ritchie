#include <emmintrin.h>
#include <stdio.h>

int main()
{
    int a[4] = { 1, 9, 3, 4 }, b[4] = { 5, 6, 8, 2 }, result[4];
    __m128i va = _mm_loadu_si128((__m128i*)a);
    __m128i vb = _mm_loadu_si128((__m128i*)b);
    __m128i vmax = _mm_max_epi32(va, vb);
    _mm_storeu_si128((__m128i*)result, vmax);
    for (int i = 0; i < 4; ++i)
        printf("%d ", result[i]);
    printf("\n");
    return 0;
}
