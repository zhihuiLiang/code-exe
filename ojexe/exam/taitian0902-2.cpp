#include <bits/stdc++.h>

int main() {
    std::string str = "[]";
    std::cout << str.size() << std::endl;
    int n, m;
    std::cin >> n >> m;
    std::unordered_map<int, int> memo;
    const auto dfs = [&](auto&& dfs, int cur, int sum) -> int {
        if (cur > n) {
            if (sum % n == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        // if (memo.count(cur))
        //     return memo[cur];

        int cnt = 0;
        for (int i = 1; i * cur <= m; ++i) {
            cnt += dfs(dfs, cur + 1, sum + i * cur);
        }

        //memo[cur] = cnt;
        return cnt;
    };
    std::cout << dfs(dfs, 1, 0) << std::endl;
    return 0;
}