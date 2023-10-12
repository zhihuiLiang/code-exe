#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int n = 0;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> priQue;
    for (int i = 0; i < n; ++i)
    {
        int cost = 0;
        std::cin >> cost;
        priQue.push(cost);
    }

    int costSum = 0;
    while (priQue.size() >= 2)
    {
        int costTwo = 0;
        for (int i = 0; i < 2; ++i)
        {
            int top = priQue.top();
            costTwo += top;
            priQue.pop();
        }
        costSum += costTwo;
        priQue.push(costTwo);
    }
    std::cout << costSum << std::endl;
    return 0;
}