#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> blankets;
    blankets.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b, x, y;
        std::cin >> a >> b >> x >> y;
        blankets.push_back(std::vector<int>{a, b, x, y});
    }
    int px, py;
    std::cin >> px >> py;
    int res = -1;
    for (int i = 0; i < blankets.size(); ++i)
    {
        if (px >= blankets[i][0] && py >= blankets[i][1] && px <= blankets[i][0] + blankets[i][2] && py <= blankets[i][1] + blankets[i][3])
        {
            res = i + 1;
        }
    }
    std::cout << res;
}