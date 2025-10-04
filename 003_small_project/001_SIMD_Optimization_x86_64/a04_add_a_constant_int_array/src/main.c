#include <emmintrin.h>
#include <stdio.h>

int main()
{
    int a[4] = { 1, 2, 3, 4 };
    int result[4];
    __m128i va = _mm_loadu_si128((__m128i*)a);
    __m128i vc = _mm_set1_epi32(10);
    __m128i vr = _mm_add_epi32(va, vc);
    _mm_storeu_si128((__m128i*)result, vr);
    for (int i = 0; i < 4; ++i)
        printf("%d ", result[i]);
    printf("\n");
    return 0;
}
