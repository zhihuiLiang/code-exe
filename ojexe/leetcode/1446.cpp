#include <vector>
#include <iostream>

using namespace std;

class Solution
{
    vector<vector<int>> map, links;
    void dfs(int curCity, vector<int> &isVisited, int &cnt)
    {
        isVisited[curCity] = 1;
        for (int i = 0; i < links[curCity].size(); ++i)
        {
            int next = links[curCity][i];
            if (!isVisited[next])
            {
                if (map[next][i] == 0)
                {
                    cnt++;
                }
                isVisited[next] = 1;
                dfs(next, isVisited, cnt);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>> connections)
    {
        map = vector<vector<int>>(n, vector<int>(n, 0));
        links = vector<vector<int>>(n);
        for (int i = 0; i < n; ++i)
        {
            int from = connections[i][0], to = connections[i][1];
            std::cout << i << " ";
            map[from][to] = 1;
            links[from].push_back(to);
            std::cout << from << " ";
            std::cout << to << std::endl;
            links[to].push_back(from);
        }
        std::cout << 1 << std::endl;
        vector<int> isVisited(n, 0);
        int cnt = 0;
        dfs(0, isVisited, cnt);
        return cnt;
    }
};

int main()
{
    Solution sln;
    sln.minReorder(6, {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}});
}