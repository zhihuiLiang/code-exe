#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

constexpr int Max = 10000;

int main() {
    int L;
    std::cin >> L;
    int S, T, M;
    std::cin >> S >> T >> M;
    std::vector<int> stone(L + 1);
    for (int i = 0; i < M; ++i) {
        int pos;
        std::cin >> pos;
        stone[pos] = 1;
    }
    int maxEnd = L + T;
    std::vector<int> dp(maxEnd, Max);
    if (stone[0] == 1) {
        dp[0] = 1;
    } else {
        dp[0] = 0;
    }
    for (int i = 0; i < maxEnd; ++i) {
        for (int j = S; j <= T; ++j) {
            if (i - j >= 0) {
                dp[i] = std::min(dp[i], dp[i - j] + stone[i]);
            }
        }
    }

    auto maxEle = std::min(dp.begin() + L, dp.end());
    std::cout << *maxEle << std::endl;
    return 0;
}