#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

constexpr int Max = 1e7;
constexpr int Mod = 100003;

struct Node
{
    int index;
    int step;
};

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adjTab(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        adjTab[x].push_back(y);
        adjTab[y].push_back(x);
    }

    std::vector<int> visited(n + 1);
    std::vector<int> minDist(n + 1, Max);
    std::vector<int> ansCnt(n + 1);
    std::queue<Node> que;
    que.push({1, 0});
    minDist[1] = 0;
    ansCnt[1] = 1;
    visited[1] = 1;

    while (!que.empty())
    {
        const Node top = que.front();
        que.pop();

        for (int i = 0; i < adjTab[top.index].size(); ++i)
        {
            int to = adjTab[top.index][i];
            auto dist = top.step + 1;
            if (dist < minDist[to])
            {
                minDist[to] = dist;
                ansCnt[to] = 1;
            }
            else if (dist == minDist[to])
                ansCnt[to] = ansCnt[to] % Mod + 1;
            if (!visited[to])
            {
                visited[top.index] = 1;
                que.push({to, dist});
            }
        }
    }

    for (int i = 1; i < ansCnt.size(); ++i)
    {
        std::cout << ansCnt[i] % Mod << std::endl;
    }
}