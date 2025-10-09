#include <iostream>
#include <omp.h>

int main() {
    std::cout << "OpenMP Example" << std::endl;

    // Example 1: Basic parallel region
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        std::cout << "Hello from thread " << thread_id
                  << " of " << num_threads << " threads \n" << std::endl;
    }
}
