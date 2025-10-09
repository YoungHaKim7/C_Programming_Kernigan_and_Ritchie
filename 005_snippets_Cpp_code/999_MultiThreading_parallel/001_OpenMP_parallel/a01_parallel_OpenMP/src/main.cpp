#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    std::cout << "OpenMP Example" << std::endl;

    // Example 1: Basic parallel region
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        std::cout << "Hello from thread " << thread_id
                  << " of " << num_threads << " threads" << std::endl;
    }

    // Example 2: Parallel for loop
    const int N = 100;
    std::vector<int> data(N, 0);

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        data[i] = i * 2;
    }

    // Example 3: Critical section
    int counter = 0;
    #pragma omp parallel for
    for (int i = 0; i < 1000; i++) {
        #pragma omp critical
        {
            counter++;
        }
    }

    std::cout << "Counter value: " << counter << std::endl;

    // Example 4: Reduction
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 100; i++) {
        sum += i;
    }

    std::cout << "Sum of 0-99: " << sum << std::endl;

    return 0;
}
