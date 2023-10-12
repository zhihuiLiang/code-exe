#include <bits/stdc++.h>

int main() {
    std::vector<int> wood = {21, 21, 21, 21, 42, 42, 84, 84, 84, 84};

    int sum = std::accumulate(wood.begin(), wood.end(), 0);
    if (sum % 4)
        std::cout << "False" << std::endl;
    int t = sum / 4;
    std::vector<int> bucket(4);
    bool ans = false;
    const auto dfs = [&](auto&& dfs, int w) -> void {
        if (ans)
            return;
        if (w >= wood.size())
            return;

        for (int i = 0; i < 4; ++i) {
            if (bucket[i] == t) {
                ans = true;
                return;
            }
        }

        for (int i = 0; i < 4; ++i) {
            if (i > 1 && bucket[i] == bucket[i - 1])
                continue;
            if (bucket[i] + wood[w] > t)
                continue;
            bucket[i] += wood[w];
            dfs(dfs, w + 1);
            bucket[i] -= wood[w];
        }
    };
    dfs(dfs, 0);
    std::cout << ans << std::endl;
    return 0;
}