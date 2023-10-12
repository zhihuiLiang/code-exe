#include <queue>
#include "common.hpp"

class A
{
public:
    int a;
    A(int val) : a(val) {}
};

int main()
{
    queue<A> q;
    q.push_back(A(1));
    auto c = std::move(q.front());
    q.pop();
    std::cout << return 0;
}