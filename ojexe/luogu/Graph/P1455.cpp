#include <iostream>
#include <vector>
#include <unordered_map>

class UF
{
public:
    int count;
    std::vector<int> parent;
    std::unordered_map<int, std::pair<int, int>> priceVal;
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
        priceVal[rootP].first += priceVal[rootQ].first;
        priceVal[rootP].second += priceVal[rootQ].second;

        priceVal.erase(rootQ);
        count--;
    }
};

int main()
{
    int n, m, w;
    std::cin >> n >> m >> w;
    UF uf(n);
    for (int i = 0; i < n; ++i)
    {
        int price, val;
        std::cin >> price >> val;
        uf.priceVal[i + 1] = std::make_pair(price, val);
    }
    for (int i = 0; i < m; ++i)
    {
        int v, u;
        std::cin >> v >> u;
        uf.unionTwo(v, u);
    }
    int numOfSet = uf.priceVal.size();
    std::vector<int> mp(numOfSet);
    int p = 0;
    for (auto it = uf.priceVal.begin(); it != uf.priceVal.end(); ++it)
    {
        mp[p++] = it->first;
    }
    std::vector<int> dp(w + 1);

    for (int i = 1; i <= numOfSet; ++i)
    {
        int price = uf.priceVal[mp[i - 1]].first, val = uf.priceVal[mp[i - 1]].second;
        for (int j = w; j >= price; --j)
        {
            dp[j] = std::max(dp[j], dp[j - price] + val);
        }
    }
    std::cout << dp[w];
    return 0;
}