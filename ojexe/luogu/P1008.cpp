#include <iostream>
#include <unordered_set>

int main()
{
    for (int i = 192; i <= 329; ++i)
    {
        int a = i, b = i * 2, c = i * 3;
        std::unordered_set<int> num;
        num.insert(a % 10);
        num.insert(a / 10 % 10);
        num.insert(a / 100);
        num.insert(b % 10);
        num.insert(b / 10 % 10);
        num.insert(b / 100);
        num.insert(c % 10);
        num.insert(c / 10 % 10);
        num.insert(c / 100);

        if (num.size() == 9 && num.count(0) == 0)
        {
            std::cout << a << " " << b << " " << c << std::endl;
        }
    }
}
