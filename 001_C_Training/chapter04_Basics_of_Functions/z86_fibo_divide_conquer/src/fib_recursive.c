// Recursive Fibonacci (inefficient - O(2^n))
long long fib_recursive(int n)
{
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}
