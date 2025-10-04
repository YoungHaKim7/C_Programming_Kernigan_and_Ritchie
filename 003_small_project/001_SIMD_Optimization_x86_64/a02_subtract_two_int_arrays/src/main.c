#include <emmintrin.h>
#include <stdio.h>

int main()
{
    int a[4] = { 10, 20, 30, 40 };
    int b[4] = { 1, 2, 3, 4 };
    int result[4];
    __m128i va = _mm_loadu_si128((__m128i*)a);
    __m128i vb = _mm_loadu_si128((__m128i*)b);
    __m128i vr = _mm_sub_epi32(va, vb);
    _mm_storeu_si128((__m128i*)result, vr);
    for (int i = 0; i < 4; ++i)
        printf("%d ", result[i]);
    printf("\n");
    return 0;
}
