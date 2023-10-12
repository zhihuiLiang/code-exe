#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> energy(2 * n);
    for (int i = 0; i < n; ++i) {
        int e;
        std::cin >> e;
        energy[i] = energy[i + n] = e;
    }

    std::vector<std::vector<int>> dp(2 * n, std::vector<int>(2 * n));
    for (int len = 2; len < n; ++len) {
        for (int i = 0; i + len < 2 * n; ++i) {
            int j = i + len;
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k][j] + energy[i] * energy[k] * energy[j]);
            }
        }
    }

    int maxAns = 0;
    for (int i = 1; i < n; ++i) {
        maxAns = std::max(dp[i][i + n], maxAns);
    }
    std::cout << maxAns << std::endl;
    return 0;
}