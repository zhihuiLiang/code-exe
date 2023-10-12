#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i].first;
    }
    int m;
    std::cin >> m;
    int i = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> vec[i].second;
    }
    int t;
    std::cin >> t;
    std::sort(vec.begin(), vec.end(), [](auto p1, auto p2) {
        return p1.first <= p2.first;
    });
    int left = 0, right = 0;
    int maxCnt = 0, sum = 0;
    while (right < n) {
        sum += vec[right].second;
        while (sum > t) {
            sum -= vec[left].second;
            left++;
        }
        maxCnt = std::max(maxCnt, right - left + 1);
        right++;
    }
    std::cout << maxCnt << std::endl;
    return 0;
}