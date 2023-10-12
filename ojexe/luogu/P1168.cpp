#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> data;
    for (int i = 0; i < n; ++i)
    {
        int index = 0;
        std::cin >> index;
        data.push_back(index);
    }
    std::vector<int> orderedData;
    for (int i = 0; i < (n + 1) / 2; ++i)
    {
        int lastIndex = 2 * i;
        for (int j = orderedData.size(); j <= lastIndex; ++j)
        {
            auto posIt = std::upper_bound(orderedData.begin(), orderedData.end(), data[j]);
            orderedData.insert(posIt, data[j]);
        }

        std::cout << orderedData[i] << std::endl;
    }
    return 0;
}