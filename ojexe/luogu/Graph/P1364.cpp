#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

constexpr int Max = 10000;

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> num;
    num.resize(n + 1);
    std::vector<std::vector<int>> adjMap;
    adjMap.resize(n + 1, std::vector<int>(n + 1, Max));
    for (int i = 0; i < n; ++i)
    {
        int n, child1, child2;
        std::cin >> n >> child1 >> child2;
        num[i + 1] = n;
        if (child1)
        {
            adjMap[i + 1][child1] = 1;
            adjMap[child1][i + 1] = 1;
        }
        if (child2)
        {
            adjMap[i + 1][child2] = 1;
            adjMap[child2][i + 1] = 1;
        }
        adjMap[i + 1][i + 1] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                adjMap[i][j] = std::min(adjMap[i][k] + adjMap[k][j], adjMap[i][j]);
            }
        }
    }

    int minDist = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        int sumDist = 0;
        for (int j = 1; j <= n; ++j)
        {
            sumDist += adjMap[i][j] * num[j];
        }
        minDist = std::min(minDist, sumDist);
    }
    std::cout << minDist << std::endl;
    return 0;
}