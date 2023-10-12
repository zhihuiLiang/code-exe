#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

class UF
{
public:
    int count;
    std::vector<int> parent;
    UF(int cnt)
    {
        count = cnt;
        parent.resize(count + 1);
        for (int i = 1; i <= count; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int p)
    {
        if (parent[p] != p)
        {
            parent[p] = find(parent[p]);
        }
        return parent[p];
    }

    bool isConnect(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);

        return rootQ == rootP;
    }

    void unionTwo(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);

        if (rootQ == rootP)
        {
            return;
        }
        parent[rootQ] = rootP;
        count--;
    }
};

struct Edge
{
    int from;
    int to;
    int weights;
};

int main()
{
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    std::vector<Edge> edges;
    for (int i = 0; i < m; ++i)
    {
        int from, to, w;
        std::cin >> from >> to >> w;
        edges.push_back({from, to, w});
    }

    std::sort(edges.begin(), edges.end(), [](const Edge &edge1, const Edge &edge2)
              { return edge1.weights < edge2.weights; });

    UF uf(n);
    for (int i = 0; i < edges.size(); ++i)
    {
        uf.unionTwo(edges[i].from, edges[i].to);
        if (uf.isConnect(s, t))
        {
            std::cout << edges[i].weights << std::endl;
            break;
        }
    }
    return 0;
}