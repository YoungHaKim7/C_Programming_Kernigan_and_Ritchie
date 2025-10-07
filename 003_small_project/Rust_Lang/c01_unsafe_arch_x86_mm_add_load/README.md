# Result

```bash
$ cargo nextest run --nocapture

running 1 test
test tests::test_associative_property ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_associative_property
       START             c01_unsafe_arch_x86_mm_add_load tests::test_commutative_property

running 1 test
test tests::test_commutative_property ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_commutative_property
       START             c01_unsafe_arch_x86_mm_add_load tests::test_floating_point_precision

running 1 test
test tests::test_floating_point_precision ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_floating_point_precision
       START             c01_unsafe_arch_x86_mm_add_load tests::test_identity_addition

running 1 test
test tests::test_identity_addition ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_identity_addition
       START             c01_unsafe_arch_x86_mm_add_load tests::test_infinity_handling

running 1 test
test tests::test_infinity_handling ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_infinity_handling
       START             c01_unsafe_arch_x86_mm_add_load tests::test_load_aligned_and_add

running 1 test
test tests::test_load_aligned_and_add ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_load_aligned_and_add
       START             c01_unsafe_arch_x86_mm_add_load tests::test_load_unaligned_and_add

running 1 test
test tests::test_load_unaligned_and_add ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_load_unaligned_and_add
       START             c01_unsafe_arch_x86_mm_add_load tests::test_memory_layout

running 1 test
test tests::test_memory_layout ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_memory_layout
       START             c01_unsafe_arch_x86_mm_add_load tests::test_nan_handling

running 1 test
test tests::test_nan_handling ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_nan_handling
       START             c01_unsafe_arch_x86_mm_add_load tests::test_performance_comparison

running 1 test
test tests::test_performance_comparison ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_performance_comparison
       START             c01_unsafe_arch_x86_mm_add_load tests::test_set_and_add_basic

running 1 test
test tests::test_set_and_add_basic ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_set_and_add_basic
       START             c01_unsafe_arch_x86_mm_add_load tests::test_set_and_add_with_large_numbers

running 1 test
test tests::test_set_and_add_with_large_numbers ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_set_and_add_with_large_numbers
       START             c01_unsafe_arch_x86_mm_add_load tests::test_set_and_add_with_negatives

running 1 test
test tests::test_set_and_add_with_negatives ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_set_and_add_with_negatives
       START             c01_unsafe_arch_x86_mm_add_load tests::test_set_and_add_with_small_numbers

running 1 test
test tests::test_set_and_add_with_small_numbers ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_set_and_add_with_small_numbers
       START             c01_unsafe_arch_x86_mm_add_load tests::test_set_and_add_with_zeros

running 1 test
test tests::test_set_and_add_with_zeros ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_set_and_add_with_zeros
       START             c01_unsafe_arch_x86_mm_add_load tests::test_stress_multiple_operations

running 1 test
test tests::test_stress_multiple_operations ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 15 filtered out; finished in 0.00s

        PASS [   0.002s] c01_unsafe_arch_x86_mm_add_load tests::test_stress_multiple_operations
────────────
     Summary [   0.035s] 16 tests run: 16 passed, 0 skipped

```


- cargo t


```bash
$ cargo t -- --nocapture

running 16 tests
test tests::test_associative_property ... ok
test tests::test_commutative_property ... ok
test tests::test_identity_addition ... ok
test tests::test_floating_point_precision ... ok
test tests::test_infinity_handling ... ok
test tests::test_load_aligned_and_add ... ok
test tests::test_load_unaligned_and_add ... ok
test tests::test_nan_handling ... ok
test tests::test_memory_layout ... ok
test tests::test_performance_comparison ... ok
test tests::test_set_and_add_basic ... ok
test tests::test_set_and_add_with_negatives ... ok
test tests::test_set_and_add_with_large_numbers ... ok
test tests::test_set_and_add_with_small_numbers ... ok
test tests::test_set_and_add_with_zeros ... ok
test tests::test_stress_multiple_operations ... ok

test result: ok. 16 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.00s

   Doc-tests c01_unsafe_arch_x86_mm_add_load

running 0 tests

test result: ok. 0 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.00s

```
