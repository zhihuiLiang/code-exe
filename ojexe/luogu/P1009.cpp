#include <iostream>
#include <vector>

void normanVec(std::vector<long long> &num)
{
    for (int i = 0; i < num.size() - 1; ++i)
    {
        num[i + 1] += num[i] / 10;
        num[i] = num[i] % 10;
    }
}

std::vector<long long> clcBigNumMulti(const std::vector<long long> &num1, const std::vector<long long> &num2)
{
    std::vector<long long> res;
    res.resize(num1.size() + num2.size() + 1);
    for (int i = 0; i < num1.size(); ++i)
    {
        for (int j = 0; j < num2.size(); ++j)
        {
            res[i + j] += num1[i] * num2[j];
        }
    }
    normanVec(res);
    return res;
}

std::vector<long long> clcBigNumSum(const std::vector<long long> &num1, const std::vector<long long> &num2)
{
    std::vector<long long> res;
    int maxLen = std::max(num1.size(), num2.size()) + 1;
    res.resize(maxLen);
    for (int i = 0; i < maxLen; ++i)
    {
        int a = i < num1.size() ? num1[i] : 0;
        int b = i < num2.size() ? num2[i] : 0;
        res[i] = a + b;
    }
    normanVec(res);
    return res;
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<long long>> eachNum;
    std::vector<long long> preNum = {1};
    for (int i = 1; i <= n; ++i)
    {
        int a = i;
        std::vector<long long> num1;
        num1.push_back(a % 10);
        num1.push_back(a / 10);
        auto multi = clcBigNumMulti(num1, preNum);
        eachNum.push_back(multi);
        preNum = multi;
    }
    preNum = {0};
    for (int i = 0; i < eachNum.size(); ++i)
    {
        auto sum = clcBigNumSum(preNum, eachNum[i]);
        preNum = sum;
    }
    int nonZeroPos = 0;
    for (int i = 0; i < preNum.size() - 1; ++i)
    {
        if (preNum[i] != 0)
        {
            nonZeroPos = i;
        }
    }
    for (int i = preNum.size() - 1; i >= 0; --i)
    {
        if (nonZeroPos < i)
        {
            continue;
        }
        std::cout << preNum[i];
    }
    return 0;
}