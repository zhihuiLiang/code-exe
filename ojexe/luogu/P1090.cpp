#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main()
{
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> priQue;
    for (int i = 0; i < n; ++i)
    {
        int weight = 0;
        std::cin >> weight;
        priQue.push(weight);
    }
    int cost = 0;
    while (priQue.size() >= 2)
    {
        int twoCost = 0;
        for (int i = 0; i < 2; ++i)
        {
            int top = priQue.top();
            // std::cout << top << std::endl;
            twoCost += top;
            priQue.pop();
        }
        cost += twoCost;
        priQue.push(twoCost);
    }

    std::cout << cost << std::endl;
    return 0;
}