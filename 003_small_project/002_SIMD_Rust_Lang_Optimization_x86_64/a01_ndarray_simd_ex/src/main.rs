use ndarray::Array1;
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
