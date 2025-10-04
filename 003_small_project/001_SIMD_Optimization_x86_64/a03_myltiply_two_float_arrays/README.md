# Result(`-mavx` 추가해야함)

```bash
$ /opt/gcc-15/bin/gcc -std=c23 -mavx -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a03_myltiply_two_float_arrays ./src/main.c
./target/a03_myltiply_two_float_arrays

2.000000 6.000000 12.000000 20.000000 30.000000 42.000000 56.000000 72.000000

```

# `-mavx` 옵션 빼면 나는 에러

```bash
AVX vector return without AVX enabled changes the ABI [-Werror=psabi]
    9 |     __m256 va = _mm256_loadu_ps(a);

In file included from /opt/gcc-15/lib/gcc/x86_64-pc-linux-gnu/15.2.0/include/immintrin.h:43,
                 from ./src/main.c:1:
/opt/gcc-15/lib/gcc/x86_64-pc-linux-gnu/15.2.0/include/avxintrin.h:853:1: error: inlining failed in call to ‘always_inline’ ‘_mm256_storeu_ps’: target specific option mismatch
  853 | _mm256_storeu_ps (float *__P, __m256 __A)
      | ^~~~~~~~~~~~~~~~
./src/main.c:12:5: note: called from here
   12 |     _mm256_storeu_ps(result, vr);
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
/opt/gcc-15/lib/gcc/x86_64-pc-linux-gnu/15.2.0/include/avxintrin.h:302:1: error: inlining failed in call to ‘always_inline’ ‘_mm256_mul_ps’: target specific option mismatch
  302 | _mm256_mul_ps (__m256 __A, __m256 __B)
      | ^~~~~~~~~~~~~
./src/main.c:11:17: note: called from here
   11 |     __m256 vr = _mm256_mul_ps(va, vb);
      |                 ^~~~~~~~~~~~~~~~~~~~~
/opt/gcc-15/lib/gcc/x86_64-pc-linux-gnu/15.2.0/include/avxintrin.h:847:1: error: inlining failed in call to ‘always_inline’ ‘_mm256_loadu_ps’: target specific option mismatch
  847 | _mm256_loadu_ps (float const *__P)
      | ^~~~~~~~~~~~~~~
./src/main.c:10:17: note: called from here
   10 |     __m256 vb = _mm256_loadu_ps(b);
      |                 ^~~~~~~~~~~~~~~~~~
/opt/gcc-15/lib/gcc/x86_64-pc-linux-gnu/15.2.0/include/avxintrin.h:847:1: error: inlining failed in call to ‘always_inline’ ‘_mm256_loadu_ps’: target specific option mismatch
  847 | _mm256_loadu_ps (float const *__P)
      | ^~~~~~~~~~~~~~~
./src/main.c:9:17: note: called from here
    9 |     __m256 va = _mm256_loadu_ps(a);
      |                 ^~~~~~~~~~~~~~~~~~
cc1: all warnings being treated as errors


```
