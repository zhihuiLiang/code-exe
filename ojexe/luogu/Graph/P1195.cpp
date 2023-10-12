#include <iostream>
#include <vector>
#include <algorithm>

class UF
{
public:
    int count;
    std::vector<int> parent;
    UF(int num)
    {
        count = num;
        parent.resize(num);
        for (int i = 0; i < num; ++i)
        {
            parent[i] = i;
        }
    }

    bool unionTwo(int p, int q)
    {
        int rootP = findParent(p);
        int rootQ = findParent(q);
        if (rootP == rootQ)
        {
            return false;
        }
        parent[rootQ] = rootP;
        count--;
        return true;
    }
    bool isConnect(int p, int q)
    {
        int rootP = findParent(p);
        int rootQ = findParent(q);
        return rootP == rootQ;
    }
    int findParent(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = findParent(parent[x]);
        }
        return parent[x];
    }
};

struct Edge
{
    int from;
    int to;
    int cost;
};

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    UF uf(n);
    std::vector<Edge> edges;
    for (int i = 0; i < m; ++i)
    {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        edges.push_back({from, to, cost});
    }
    std::sort(edges.begin(), edges.end(), [](const Edge &edge1, const Edge &edge2)
              { return edge1.cost < edge2.cost; });
    int cost = 0;
    for (int i = 0; i < edges.size() && uf.count > k; ++i)
    {
        if (uf.unionTwo(edges[i].from, edges[i].to))
        {
            cost += edges[i].cost;
        }
    }
    std::cout << cost << std::endl;
    return 0;
}