#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Node
{
    int index;
    int t;
    bool operator>(const Node &other) const
    {
        return t > other.t;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adjTab(n + 1);
    std::vector<int> costTime(n + 1);
    std::vector<int> inDegree(n + 1), outDegree(n + 1);
    for (int i = 0; i < n; ++i)
    {
        int to, t;
        std::cin >> to >> t;
        costTime[to] = t;
        while (1)
        {
            int from;
            std::cin >> from;
            if (!from)
                break;
            adjTab[from].push_back(to);
            inDegree[to]++;
            outDegree[from]++;
        }
    }

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> priQue;
    for (int i = 1; i <= n; ++i)
    {
        if (inDegree[i] == 0)
        {
            priQue.push({i, costTime[i]});
        }
    }

    while (!priQue.empty())
    {
        Node top = priQue.top();
        priQue.pop();

        for (int i = 0; i < adjTab[top.index].size(); ++i)
        {
            int to = adjTab[top.index][i];
            inDegree[to]--;
            if (inDegree[to] == 0)
            {
                priQue.push({to, top.t + costTime[to]});
            }
        }

        if (priQue.empty())
        {
            std::cout << top.t << std::endl;
        }
    }
    return 0;
}