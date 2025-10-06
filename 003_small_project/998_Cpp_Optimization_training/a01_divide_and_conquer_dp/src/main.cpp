#include <bits/stdc++.h>

int m, n;
std::vector<long long> dp_before, dp_cur;

// Example cost function - can be customized based on specific problem
long long C(int i, int j)
{
    if (i > j)
        return 0;
    // Simple example: cost is the distance between i and j squared
    return (long long)(j - i) * (j - i);
}

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr)
{
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    std::pair<long long, int> best = { LLONG_MAX, -1 };

    for (int k = optl; k <= std::min(mid, optr); k++) {
        best = min(best, { (k ? dp_before[k - 1] : 0) + C(k, mid), k });
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

long long solve()
{
    dp_before.assign(n, 0);
    dp_cur.assign(n, 0);

    for (int i = 0; i < n; i++)
        dp_before[i] = C(0, i);

    for (int i = 1; i < m; i++) {
        compute(0, n - 1, 0, n - 1);
        dp_before = dp_cur;
    }

    return dp_before[n - 1];
}
int main(void)
{
    // Test Case 1: Basic case
    m = 2, n = 5;
    std::cout << "Test 1 (m=2, n=5): " << solve() << std::endl;

    // Test Case 2: Small case
    m = 1, n = 3;
    std::cout << "Test 2 (m=1, n=3): " << solve() << std::endl;

    // Test Case 3: Equal dimensions
    m = 3, n = 3;
    std::cout << "Test 3 (m=3, n=3): " << solve() << std::endl;

    // Test Case 4: More partitions than elements
    m = 5, n = 2;
    std::cout << "Test 4 (m=5, n=2): " << solve() << std::endl;

    // Test Case 5: Large n, small m
    m = 2, n = 10;
    std::cout << "Test 5 (m=2, n=10): " << solve() << std::endl;

    // Test Case 6: Medium case
    m = 3, n = 7;
    std::cout << "Test 6 (m=3, n=7): " << solve() << std::endl;

    // Test Case 7: Single element
    m = 1, n = 1;
    std::cout << "Test 7 (m=1, n=1): " << solve() << std::endl;

    // Test Case 8: Larger case
    m = 4, n = 8;
    std::cout << "Test 8 (m=4, n=8): " << solve() << std::endl;

    // Test Case 9: Many partitions
    m = 6, n = 6;
    std::cout << "Test 9 (m=6, n=6): " << solve() << std::endl;

    // Test Case 10: Large case
    m = 3, n = 15;
    std::cout << "Test 10 (m=3, n=15): " << solve() << std::endl;

    return 0;
}
