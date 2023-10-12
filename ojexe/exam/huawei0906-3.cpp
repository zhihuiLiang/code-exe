#include <bits/stdc++.h>

std::unordered_map<int, std::unordered_set<int>> refMap;
std::unordered_map<int, int> order;
std::unordered_map<int, int> memo;
std::vector<std::pair<int, int>> ans;

int dfs(int cur) {
    int cnt = 0;
    if (!refMap.count(cur))
        return cnt;
    if (memo[cur] != 0)
        return cnt;
    auto next = refMap[cur];
    for (auto it = next.begin(); it != next.end(); ++it) {
        cnt += (dfs(*it) + 1);
    }
    ans.push_back({cur, cnt});
    memo[cur] = cnt;
    return cnt;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int n, ref;
        char op;
        std::cin >> n >> ref >> op;
        if (!order.count(n)) {
            order.insert({n, order.size()});
        }
        if (op == '+') {
            refMap[n].insert(ref);
        } else if (op == '-') {
            refMap[n].erase(ref);
        }
    }
    int sz = order.size();
    for (auto it = order.begin(); it != order.end(); ++it) {
        int num = it->first;
        if (!memo.count(num)) {
            dfs(num);
        }
    }
    std::sort(ans.begin(), ans.end(), [&](auto p1, auto p2) {
        return order[p1.first] < order[p2.first];
    });
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i].second == 0)
            continue;
        std::cout << ans[i].first << " " << ans[i].second << std::endl;
    }
    std::cout << 0;
    return 0;
}