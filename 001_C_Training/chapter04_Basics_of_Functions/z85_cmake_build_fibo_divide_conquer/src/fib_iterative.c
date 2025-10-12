// Iterative Fibonacci (efficient - O(n))
long long fib_iterative(int n)
{
    if (n <= 1)
        return n;

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
