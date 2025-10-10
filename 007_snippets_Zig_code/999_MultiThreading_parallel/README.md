# Making A Program Faster - Multithreading & Automatic Compiler Vectorization - Ivica Bogosavljevic
CppNow
- https://youtu.be/GTAE_znTvuk?si=6qGH021DzJkyalHr


```cpp
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
```

- result

```bash

OpenMP Example
Hello from thread 1 of 8 threads

Hello from thread Hello from thread 4 of 8 threads
Hello from thread Hello from thread 3 of 8 threads
Hello from thread
Hello from thread Hello from thread 7 of 8 threads

0 of 8 threads


2 of 8 threads
65 of 8 threads


 of 8 threads

```
