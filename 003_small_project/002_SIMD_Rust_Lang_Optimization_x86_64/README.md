# Optimising path tracing with SIMD
- https://bitshifter.github.io/2018/06/04/simd-path-tracing/

# Performance optimization, and how to do it wrong - some things I learned implementing SIMD convolution in Rust 
- https://www.reddit.com/r/rust/comments/1j2iqhq/performance_optimization_and_how_to_do_it_wrong/

# ndarray _ SIMD활용 케이스
- The ndarray crate in Rust provides an n-dimensional array type, and it can leverage SIMD (Single Instruction, Multiple Data) optimizations for performance. While ndarray itself doesn't directly expose SIMD vectors as a public API, it often uses them internally when performing operations on numeric arrays, especially when compiled with appropriate features and a sufficiently modern CPU.
Here is an example demonstrating how ndarray operations can implicitly benefit from SIMD, focusing on a common numerical task like element-wise addition:
  - Rust의 ndarray 상자는 n차원 배열 유형을 제공하며, 성능을 위해 SIMD(Single Instruction, Multiple Data) 최적화를 활용할 수 있습니다. ndarray 자체는 SIMD 벡터를 공개 API로 직접 노출하지는 않지만, 특히 적절한 기능과 충분히 현대적인 CPU로 컴파일할 때 내부적으로 이를 사용하는 경우가 많습니다.
다음은 요소별 덧셈과 같은 일반적인 수치 작업에 초점을 맞추어 ndarray 연산이 SIMD로부터 암묵적으로 어떻게 이점을 얻을 수 있는지 보여주는 예시입니다:


```rs

use ndarray::{Array1, ArrayView1, arr1};
use std::time::Instant;

fn main() {
    // Create two large 1D arrays
    let size = 1_000_000;
    let a = Array1::<f32>::from_elem(size, 1.0);
    let b = Array1::<f32>::from_elem(size, 2.0);

    // Perform element-wise addition using ndarray's operator overloading
    let now = Instant::now();
    let c = &a + &b; // This operation can be optimized with SIMD by ndarray
    let elapsed = now.elapsed();

    println!("ndarray element-wise addition of {} elements:", size);
    println!("Result (first 5 elements): {:?}", c.slice(ndarray::s![..5]));
    println!("Time taken: {:?}", elapsed);

    // For comparison, a naive loop without explicit SIMD
    let mut d = Array1::<f32>::zeros(size);
    let now_naive = Instant::now();
    for i in 0..size {
        d[i] = a[i] + b[i];
    }
    let elapsed_naive = now_naive.elapsed();

    println!("\nNaive loop element-wise addition of {} elements:", size);
    println!("Result (first 5 elements): {:?}", d.slice(ndarray::s![..5]));
    println!("Time taken: {:?}", elapsed_naive);
}
```


# burn러스트 머시러닝 라이브러리-[Feat] SIMD acceleration for ndarray backend #2851  
- https://github.com/tracel-ai/burn/pull/2851/

# simd_saturating_sub
- https://doc.rust-lang.org/nightly/std/intrinsics/simd/fn.simd_saturating_sub.html