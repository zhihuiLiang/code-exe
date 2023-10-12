#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    std::vector<std::vector<long long>> dp(n, std::vector<long long>(k + 1));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = stoll(s.substr(0, i + 1));
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int m = i; m >= 1; --m) {
                long long num = stoi(s.substr(m, i - m + 1));
                dp[i][j] = std::max(dp[i][j], dp[m - 1][j - 1] * num);
            }
        }
    }

    std::cout << dp[n - 1][k] << std::endl;
    return 0;
}
