#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> color;
std::vector<int> visited;
std::vector<std::vector<int>> adjTab;
int n, cnt1, cnt2;

void travese(int from, bool &isPossible)
{
    if (!isPossible)
        return;

    visited[from] = true;
    int anotherColor = color[from] == 1 ? 2 : 1;
    for (int i = 0; i < adjTab[from].size(); ++i)
    {
        int to = adjTab[from][i];
        if (color[to] == color[from])
        {
            isPossible = false;
            return;
        }
        else if (color[to] == 0)
        {
            color[to] = anotherColor;
        }

        if (!visited[to])
        {
            travese(to, isPossible);
        }
    }
}

int main()
{
    int m;
    std::cin >> n >> m;
    color.resize(n + 1);
    visited.resize(n + 1);
    adjTab.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        adjTab[u].push_back(v);
        adjTab[v].push_back(u);
    }

    color[1] = 1;
    bool isPossible = true;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            travese(i, isPossible);
        }
        if (!isPossible)
        {
            std::cout << "Impossible" << std::endl;
            return 0;
        }
    }

    for (int i = 1; i < color.size(); ++i)
    {
        if (color[i] == 1)
        {
            cnt2++;
        }
        else if (color[i] == 1)
        {
            cnt1++;
        }
    }
    std::cout << std::min(cnt1, cnt2) << std::endl;

    return 0;
}