#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

std::vector<int> weights;
std::vector<std::vector<int>> adjTab;
int gCenter = 0, maxNum = INT_MAX, n;

void dfs(int cur, int from)
{
    weights[cur] = 1;
    int res = 0;
    for (int i = 0; i < adjTab[cur].size(); ++i)
    {
        int to = adjTab[cur][i];
        if (to == from)
            continue;
        dfs(to, cur);

        weights[cur] += weights[to];
        res = std::max(res, weights[to]);
    }
    res = std::max(res, n - weights[cur]);
    if (res < maxNum || (res == maxNum && gCenter > cur))
    {
        gCenter = cur;
        maxNum = res;
    }
}

struct Node
{
    int idx;
    int step;
};

int main()
{
    std::cin >> n;
    adjTab.resize(n + 1);
    weights.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        adjTab[a].push_back(b);
        adjTab[b].push_back(a);
    }
    dfs(1, 0);
    std::cout << "g center:" << gCenter << std::endl;
    std::vector<int> visited(n + 1);
    std::queue<Node> que;
    que.push({gCenter, 0});

    int sumStep = 0;
    while (!que.empty())
    {
        Node top = que.front();
        visited[top.idx] = 1;
        que.pop();
        sumStep += top.step;

        for (int i = 0; i < adjTab[top.idx].size(); ++i)
        {
            int to = adjTab[top.idx][i];
            if (visited[to])
                continue;
            que.push({to, top.step + 1});
        }
    }

    std::cout << gCenter << " " << sumStep << std::endl;
    return 0;
}