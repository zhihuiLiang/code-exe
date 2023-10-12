#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> vec(n);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    std::vector<int> indegree(n);
    std::vector<std::vector<int>> to(n);
    std::vector<int> visited(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num;
            std::cin >> num;
            if (num) {
                indegree[i]++;
                to[j].push_back(i);
            }
        }
    }

    return 0;
}