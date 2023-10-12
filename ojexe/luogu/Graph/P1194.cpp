#include <vector>
#include <iostream>
#include <algorithm>

class UF
{
public:
    int count;
    std::vector<int> parent;
    UF(int cnt)
    {
        count = cnt;
        parent.resize(cnt);
        for (int i = 0; i < cnt; ++i)
        {
            parent[i] = i;
        }
    }
    int findParent(int x)
    {
        if (x != parent[x])
        {
            parent[x] = findParent(parent[x]);
        }
        return parent[x];
    }
    bool isConnect(int p, int q)
    {
        return findParent(p) == findParent(q);
    }
    void unioTwo(int p, int q)
    {
        int rootP = findParent(p);
        int rootQ = findParent(q);

        if (rootQ == rootP)
        {
            return;
        }
        parent[rootP] = rootQ;
        count--;
    }
};

struct Edges
{
    int from, to;
    int cost;
};

int main()
{
    int A, B;
    std::cin >> A >> B;

    std::vector<std::vector<int>> adjMap(B, std::vector<int>(B));
    for (int i = 0; i < B; ++i)
    {
        for (int j = 0; j < B; ++j)
        {
            int k;
            std::cin >> k;
            adjMap[i][j] = k;
        }
    }
    std::vector<Edges> edges;
    for (int i = 0; i < B; ++i)
    {
        for (int j = i; j < B; ++j)
        {
            if (adjMap[i][j] != 0)
            {
                edges.push_back({i, j, adjMap[i][j]});
            }
        }
    }
    std::sort(edges.begin(), edges.end(), [](const Edges &edge1, const Edges &edge2)
              { return edge1.cost < edge2.cost; });
    UF uf(B);
    int ans = 0;
    for (auto edge : edges)
    {
        if (!uf.isConnect(edge.from, edge.to))
        {
            uf.unioTwo(edge.from, edge.to);
            ans += edge.cost;
        }
    }
    ans += uf.count * A;
    if (ans < A * B)
    {
        std::cout << ans << std::endl;
    }
    else
    {
        std::cout << A * B << std::endl;
    }

    return 0;
}