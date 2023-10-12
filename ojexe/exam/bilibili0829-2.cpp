#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string str1, str2;
    std::getline(std::cin, str1, ',');
    str1 = str1.substr(1, str1.size() - 2);
    // std::cout << str1 << std::endl;
    std::getline(std::cin, str2);
    str2 = str2.substr(1, str2.size() - 2);
    // std::cout << str2 << std::endl;

    int n1 = str1.size(), n2 = str2.size();
    std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1));
    for (int i = 1; i < n1 + 1; ++i) {
        dp[i][0] = dp[i - 1][0] + str1[i - 1];
    }
    for (int j = 1; j < n2 + 1; ++j) {
        dp[0][j] = dp[0][j - 1] + str2[j - 1];
    }
    for (int i = 1; i < n1 + 1; ++i) {
        for (int j = 1; j < n2 + 1; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min(dp[i - 1][j] + str1[i - 1], dp[i][j - 1] + str2[j - 1]);
            }
        }
    }

    std::cout << dp[n1][n2] << std::endl;
}