#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    std::unordered_set<int> weights;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                dp[i][j] = vec[i];
            } else {
                dp[i][j] = dp[i][j - 1] | vec[j];
            }
            //std::cout << dp[i][j] << std::endl;
            weights.insert(dp[i][j]);
        }
    }
    std::cout << weights.size() << std::endl;
    return 0;
}