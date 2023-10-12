#include <iostream>
#include <vector>
#include <unordered_map>

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

int main()
{
    int first;
    while (1)
    {
        std::cin >> first;
        if (!first)
            break;
        int second;
        std::cin >> second;
        UF uf(first);
        for (int i = 0; i < second; ++i)
        {
            int from, to;
            std::cin >> from >> to;
            uf.unionTwo(from, to);
        }
        std::cout << uf.count - 1 << std::endl;
    }

    return 0;
}