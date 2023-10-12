#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> dp(n);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j >= 1; --j) {
            dp[i] += (dp[j - 1] * dp[i - j + 1]);
        }
        }
    return 0;
}