#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main()
{
    int m, n, horseX, horseY;
    std::cin >> m >> n >> horseX >> horseY;

    std::vector<std::vector<long long>> steps(m + 1, std::vector<long long>(n + 1, 0));
    steps[0][0] = 1;
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == horseX && j == horseY)
                continue;

            if ((std::abs(i - horseX) + std::abs(j - horseY)) == 3 && std::max(std::abs(i - horseX), std::abs(j - horseY)) == 2)
                continue;
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                steps[i][j] = steps[i - 1][j] + steps[i][j - 1];
            }
            else if (i - 1 >= 0)
            {
                steps[i][j] = steps[i - 1][j];
            }
            else if (j - 1 >= 0)
            {
                steps[i][j] = steps[i][j - 1];
            }
        }
    }
    std::cout << steps[m][n] << std::endl;
    return 0;
}