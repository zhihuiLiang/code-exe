#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<std::vector<int>> adjTab;
std::vector<std::vector<int>> dp;
std::vector<int> weights;

bool isSqure(int num)
{
    double root = std::sqrt(num) + 1e-6;
    int rootInt = static_cast<int>(root);
    return rootInt * rootInt == num;
}

void dfs(int cur, int from)
{
    for (int i = 0; i < adjTab[cur].size(); ++i)
    {
        int next = adjTab[cur][i];
        if (next == from)
            continue;
        dfs(next, cur);
        if (isSqure(weights[cur] * weights[next]))
        {
            dp[cur][1] = std::max(dp[cur][1], dp[next][0] + 2);
        }
        dp[cur][0] = std::max(dp[cur][0], std::max(dp[next][0], dp[next][1]));
    }
}

int main()
{
    int n;
    std::cin >> n;
    weights.resize(n + 1);
    for (int i = 1; i < weights.size(); ++i)
    {
        std::cin >> weights[i];
    }
    adjTab.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        adjTab[u].push_back(v);
        adjTab[v].push_back(u);
    }

    dp.resize(n + 1, std::vector<int>(2));
    dfs(1, 0);
    std::cout << std::max(dp[1][0], dp[1][1]) << std::endl;

    return 0;
}