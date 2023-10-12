#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int L, n = 0;
    std::cin >> L >> n;
    int minPos = L + 1, maxPos = 0;
    int minTime = 0, maxTime = 0;
    std::vector<int> pos;
    for (int i = 0; i < n; ++i)
    {
        int p;
        std::cin >> p;
        minTime = std::max(std::min(p, L + 1 - p), minTime);
        minPos = std::min(p, minPos);
        maxPos = std::max(p, maxPos);
    }
    maxTime = std::max(std::max(minPos, L + 1 - minPos), std::max(maxPos, L + 1 - maxPos));
    std::cout << minTime << " " << maxTime << std::endl;
}