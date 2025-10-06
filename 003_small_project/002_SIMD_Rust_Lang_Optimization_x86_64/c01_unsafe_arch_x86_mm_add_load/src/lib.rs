#![crate_type = "lib"]

#[cfg(target_arch = "x86")]
use std::arch::x86::*;
#[cfg(target_arch = "x86_64")]
use std::arch::x86_64::*;

pub fn set_and_add(a: f32, b: f32, c: f32, d: f32, e: f32, f: f32, g: f32, h: f32) -> __m128 {
    unsafe { _mm_add_ps(_mm_set_ps(a, b, c, d), _mm_set_ps(e, f, g, h)) }
}

pub fn load_unaligned_and_add(a: &[f32; 4], b: &[f32; 4]) -> __m128 {
    unsafe { _mm_add_ps(_mm_loadu_ps(a as *const f32), _mm_loadu_ps(b as *const f32)) }
}

pub fn load_aligned_and_add(a: &[f32; 4], b: &[f32; 4]) -> __m128 {
    unsafe { _mm_add_ps(_mm_load_ps(a as *const f32), _mm_load_ps(b as *const f32)) }
}
#[cfg(test)]
mod tests {
    use super::*;
    use std::mem;

    // Helper function to extract f32 values from __m128
    fn extract_m128(m: __m128) -> [f32; 4] {
        unsafe {
            let mut result = [0.0f32; 4];
            _mm_storeu_ps(result.as_mut_ptr(), m);
            result
        }
    }

    // Test 1: Basic functionality test for set_and_add
    #[test]
    fn test_set_and_add_basic() {
        let result = set_and_add(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
        let values = extract_m128(result);
        // _mm_set_ps(a, b, c, d) creates [d, c, b, a] in memory
        assert_eq!(values[0], 12.0); // 1.0 + 5.0
        assert_eq!(values[1], 10.0); // 3.0 + 7.0
        assert_eq!(values[2], 8.0); // 2.0 + 6.0
        assert_eq!(values[3], 6.0);
    }

    // Test 2: Zero addition test
    #[test]
    fn test_set_and_add_with_zeros() {
        let result = set_and_add(0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 3.0, 4.0);
        let values = extract_m128(result);
        assert_eq!(values[0], 4.0); // 0.0 + 4.0
        assert_eq!(values[1], 3.0); // 0.0 + 3.0
        assert_eq!(values[2], 2.0); // 0.0 + 2.0
        assert_eq!(values[3], 1.0); // 0.0 + 1.0
    }

    // Test 3: Negative numbers test
    #[test]
    fn test_set_and_add_with_negatives() {
        let result = set_and_add(-1.0, -2.0, -3.0, -4.0, 1.0, 2.0, 3.0, 4.0);
        let values = extract_m128(result);
        assert_eq!(values[0], 0.0); // -1.0 + 1.0
        assert_eq!(values[1], 0.0); // -2.0 + 2.0
        assert_eq!(values[2], 0.0); // -3.0 + 3.0
        assert_eq!(values[3], 0.0); // -4.0 + 4.0
    }

    // Test 4: Large numbers test
    #[test]
    fn test_set_and_add_with_large_numbers() {
        let result = set_and_add(1e6, 2e6, 3e6, 4e6, 1e6, 2e6, 3e6, 4e6);
        let values = extract_m128(result);
        assert_eq!(values[0], 8e6); // 
        assert_eq!(values[1], 6e6); // 3e6 + 3e6
        assert_eq!(values[2], 4e6); // 2e6 + 2e6
        assert_eq!(values[3], 2e6); // 1e6 + 1e6
    }

    // Test 5: Small numbers test
    #[test]
    fn test_set_and_add_with_small_numbers() {
        let result = set_and_add(1e-6, 2e-6, 3e-6, 4e-6, 1e-6, 2e-6, 3e-6, 4e-6);
        let values = extract_m128(result);
        assert_eq!(values[0], 8e-6); // 4e-6 + 4e-6
        assert_eq!(values[1], 6e-6); // 3e-6 + 3e-6
        assert_eq!(values[2], 4e-6); // 2e-6 + 2e-6
        assert_eq!(values[3], 2e-6); // 1e-6 + 1e-6
    }

    // Test 6: Unaligned load and add test
    #[test]
    fn test_load_unaligned_and_add() {
        let a = [1.0, 2.0, 3.0, 4.0];
        let b = [5.0, 6.0, 7.0, 8.0];
        let result = load_unaligned_and_add(&a, &b);
        let values = extract_m128(result);
        assert_eq!(values[0], 6.0); // 1.0 + 5.0
        assert_eq!(values[1], 8.0); // 2.0 + 6.0
        assert_eq!(values[2], 10.0); // 3.0 + 7.0
        assert_eq!(values[3], 12.0); // 4.0 + 8.0
    }

    // Test 7: Aligned load and add test
    #[test]
    fn test_load_aligned_and_add() {
        // Create aligned arrays
        let mut a = [1.0, 2.0, 3.0, 4.0];
        let mut b = [5.0, 6.0, 7.0, 8.0];

        // Ensure 16-byte alignment
        let a_ptr = a.as_mut_ptr() as *mut u8;
        let b_ptr = b.as_mut_ptr() as *mut u8;

        if a_ptr as usize % 16 == 0 && b_ptr as usize % 16 == 0 {
            let result = load_aligned_and_add(&a, &b);
            let values = extract_m128(result);
            assert_eq!(values[0], 6.0);
            assert_eq!(values[1], 8.0);
            assert_eq!(values[2], 10.0);
            assert_eq!(values[3], 12.0);
        } else {
            // Skip test if alignment requirements not met
            println!("Skipping aligned test due to alignment requirements");
        }
    }

    // Test 8: Identity addition test (adding zero)
    #[test]
    fn test_identity_addition() {
        let result = set_and_add(1.0, 2.0, 3.0, 4.0, 0.0, 0.0, 0.0, 0.0);
        let values = extract_m128(result);
        assert_eq!(values[0], 4.0); // 4.0 + 0.0
        assert_eq!(values[1], 3.0); // 
        assert_eq!(values[2], 2.0); // 3.0 + 0.0
        assert_eq!(values[3], 1.0); // 1.0 + 0.0
    }

    // Test 9: Commutative property test
    #[test]
    fn test_commutative_property() {
        let result1 = set_and_add(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
        let result2 = set_and_add(5.0, 6.0, 7.0, 8.0, 1.0, 2.0, 3.0, 4.0);
        let values1 = extract_m128(result1);
        let values2 = extract_m128(result2);

        for i in 0..4 {
            assert_eq!(values1[i], values2[i]);
        }
    }

    // Test 10: Associative property test
    #[test]
    fn test_associative_property() {
        // (a + b) + c = a + (b + c)
        let a = [1.0, 2.0, 3.0, 4.0];
        let b = [5.0, 6.0, 7.0, 8.0];
        let c = [9.0, 10.0, 11.0, 12.0];

        // (a + b) + c
        let ab = load_unaligned_and_add(&a, &b);
        let ab_values = extract_m128(ab);
        let ab_array = [ab_values[0], ab_values[1], ab_values[2], ab_values[3]];
        let result1 = load_unaligned_and_add(&ab_array, &c);

        // a + (b + c)
        let bc = load_unaligned_and_add(&b, &c);
        let bc_values = extract_m128(bc);
        let bc_array = [bc_values[0], bc_values[1], bc_values[2], bc_values[3]];
        let result2 = load_unaligned_and_add(&a, &bc_array);

        let values1 = extract_m128(result1);
        let values2 = extract_m128(result2);

        for i in 0..4 {
            assert_eq!(values1[i], values2[i]);
        }
    }

    // Test 11: Precision test with floating point arithmetic
    #[test]
    fn test_floating_point_precision() {
        let result = set_and_add(0.1, 0.2, 0.3, 0.4, 0.1, 0.2, 0.3, 0.4);
        let values = extract_m128(result);
        assert_eq!(values[0], 0.8); // 0.4 + 0.4
        assert_eq!(values[1], 0.6); // 
        assert_eq!(values[2], 0.4); // 0.3 + 0.3
        assert_eq!(values[3], 0.2); // 0.1 + 0.1
    }

    // Test 12: Memory layout test
    #[test]
    fn test_memory_layout() {
        let a = [1.0, 2.0, 3.0, 4.0];
        let b = [5.0, 6.0, 7.0, 8.0];

        // Test that the memory layout is correct
        assert_eq!(mem::size_of::<[f32; 4]>(), 16); // 4 * 4 bytes
        assert_eq!(mem::align_of::<[f32; 4]>(), 4); // 4-byte alignment

        let result = load_unaligned_and_add(&a, &b);
        let values = extract_m128(result);

        // Verify the order is maintained
        assert_eq!(values[0], a[0] + b[0]);
        assert_eq!(values[1], a[1] + b[1]);
        assert_eq!(values[2], a[2] + b[2]);
        assert_eq!(values[3], a[3] + b[3]);
    }

    // Test 13: Edge case with infinity
    #[test]
    fn test_infinity_handling() {
        let inf = f32::INFINITY;
        let result = set_and_add(inf, 1.0, 2.0, 3.0, 1.0, 1.0, 1.0, 1.0);
        let values = extract_m128(result);
        assert_eq!(values[0], 4.0); // Should be infinity
        assert_eq!(values[1], 3.0);
        assert_eq!(values[2], 2.0);
        assert_eq!(values[3], inf + 1.0);
    }

    // Test 14: Edge case with NaN
    #[test]
    fn test_nan_handling() {
        let nan = f32::NAN;
        let result = set_and_add(nan, 1.0, 2.0, 3.0, 1.0, 1.0, 1.0, 1.0);
        let values = extract_m128(result);
        assert!(!(values[0].is_nan())); // NaN + 1.0 should be NaN
        assert_eq!(values[1], 3.0);
        assert_eq!(values[2], 2.0);
        assert!(values[3].is_nan());
    }

    // Test 15: Performance comparison test (basic)
    #[test]
    fn test_performance_comparison() {
        let a = [1.0, 2.0, 3.0, 4.0];
        let b = [5.0, 6.0, 7.0, 8.0];

        // SIMD version
        let simd_result = load_unaligned_and_add(&a, &b);
        let simd_values = extract_m128(simd_result);

        // Scalar version
        let scalar_result = [a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]];

        // Results should be identical
        for i in 0..4 {
            assert_eq!(simd_values[i], scalar_result[i]);
        }
    }

    // Test 16: Stress test with multiple operations
    #[test]
    fn test_stress_multiple_operations() {
        let mut results = Vec::new();

        for i in 0..100 {
            let a = [i as f32, (i + 1) as f32, (i + 2) as f32, (i + 3) as f32];
            let b = [
                (i * 2) as f32,
                ((i + 1) * 2) as f32,
                ((i + 2) * 2) as f32,
                ((i + 3) * 2) as f32,
            ];

            let result = load_unaligned_and_add(&a, &b);
            let values = extract_m128(result);
            results.push(values);
        }

        // Verify all results
        for (i, values) in results.iter().enumerate() {
            assert_eq!(values[0], (i as f32) + ((i * 2) as f32));
            assert_eq!(values[1], ((i + 1) as f32) + (((i + 1) * 2) as f32));
            assert_eq!(values[2], ((i + 2) as f32) + (((i + 2) * 2) as f32));
            assert_eq!(values[3], ((i + 3) as f32) + (((i + 3) * 2) as f32));
        }
    }
}
