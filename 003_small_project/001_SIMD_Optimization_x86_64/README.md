# What is SIMD ? | Joshua Weinstein
- https://youtu.be/YuUMCVX3UVE?si=3hP-kD4v7fe85L93

# (211101)Flynn's Architecture - SISD, SIMD, MISD & MIMD
- Learn Learn Scratch Tutorials
  - https://youtu.be/KVOc6369-Lo?si=J4MuZ24EH_cYcqd6

# (210418) Intro to Parallelism with Flynn's Taxonomy | Intermation
- https://youtu.be/MJ-ettBDJqQ?si=79JAVr1tAMzG5btI


```c

__m128 va = _mm_loadu_ps(a[i]); // load 4 floats from row i of A
__m128 vb = _mm_loadu_ps(b[i]); // load 4 floats from row i of B
__m128 vr = _mm_add_ps(va, vb); // element-wise add
_mm_storeu_ps(result[i], vr); // store result into row i


// __128i
// 128 - bit registers

// `vqaddq_u8`
// v -> Vector
// q  -> Quad-word(128=bits)
// add -> Operation
// q -> Saturating
// _u8 -> Unsigned 8-bit

// Vector Quad-word Saturating Add on Unigned 8-bit integers
```

# Introduction to SIMD | i64
- https://youtu.be/hAlSKGgz-h0?si=3GTd9DULie6Xz5Ji

# x86 SIMD instruction listings
- https://en.wikipedia.org/wiki/X86_SIMD_instruction_listings