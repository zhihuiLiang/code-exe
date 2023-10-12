#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> adjTab(n);

    for (int i = 0; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        adjTab[u].push_back(v);
    }
}