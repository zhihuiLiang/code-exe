#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

std::vector<int> dp;
std::vector<int> beauty;
std::vector<std::vector<int>> flowerMap;

void dfs(int node, int parent)
{
    dp[node] = beauty[node];
    for (int i = 0; i < flowerMap[node].size(); ++i)
    {
        int to = flowerMap[node][i];
        if (to == parent)
            continue;
        dfs(to, node);

        if (dp[to] > 0)
        {
            dp[node] += dp[to];
        }
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    beauty.resize(n + 1);
    dp.resize(n + 1, INT_MIN);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> beauty[i];
    }
    flowerMap.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int from, to;
        std::cin >> from >> to;
        flowerMap[from].push_back(to);
        flowerMap[to].push_back(from);
    }
    dfs(1, 0);
    auto maxIt = std::max_element(dp.begin(), dp.end());
    std::cout << *maxIt << std::endl;
    return 0;
}