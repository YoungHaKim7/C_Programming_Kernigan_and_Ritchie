// Optimized Fibonacci (space-efficient - O(1) space)
long long fib_optimized(int n)
{
    if (n <= 1)
        return n;

    long long prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        curr = prev + curr;
        prev = curr - prev;
    }
    return curr;
}
