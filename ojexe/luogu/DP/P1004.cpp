#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Node {
    int sum;
    int parent;  // 0 left; 1 up; -1 source node;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<Node>> dp(n + 1, std::vector<Node>(n + 1));
    while (1) {
        int x, y, num;
        std::cin >> x >> y >> num;
        if (x == 0)
            break;
        graph[x][y] = num;
    }

    dp[1][1] = {graph[1][1], -1};
    const auto dpFind = [&]() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dp[i - 1][j].sum > dp[i][j - 1].sum) {
                    dp[i][j].sum = graph[i][j] + dp[i - 1][j].sum;
                    dp[i][j].parent = 1;
                } else {
                    dp[i][j].sum = graph[i][j] + dp[i][j - 1].sum;
                    dp[i][j].parent = 0;
                }
            }
        }
    };
    dpFind();
    int curX = n, curY = n;
    auto curNode = dp[n][n];
    int sum = curNode.sum;
    while (curX + curY > 0) {
        graph[curX][curY] = 0;
        if (curNode.parent == 1) {
            curX -= 1;
        } else if (curNode.parent == 0) {
            curY -= 1;
        }
        curNode = dp[curX][curY];
    }
    dp.clear();
    dp.resize(n + 1, std::vector<Node>(n + 1));
    dpFind();
    sum += dp[n][n].sum;

    std::cout << sum << std::endl;
    return 0;
}