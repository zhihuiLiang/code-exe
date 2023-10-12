#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int mod(int x) {
    int ans = x % 10;
    if (ans < 0) {
        ans += 10;
    }
    return ans;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::vector<int> preSum(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        preSum[i] = preSum[i - 1] + nums[i - 1];
    }
    const auto clcSum = [&](int i, int j) {
        if (j >= i) {
            return preSum[j] - preSum[i];
        } else {
            return preSum[n] - preSum[i] + preSum[j];
        }
    };

    int maxAns = 0, minAns = INT_MAX;
    auto dfs = [&](auto&& dfs, int head, int preMul, std::vector<int> pos) -> void {
        if (pos.size() == m) {
            preMul *= mod(clcSum(pos.back(), pos[0]));
            maxAns = std::max(maxAns, preMul);
            minAns = std::min(minAns, preMul);
            return;
        }

        for (int i = head; i < n; ++i) {
            pos.push_back(i);
            int temp = preMul;
            if (pos.size() > 1) {
                temp *= mod(clcSum(pos[pos.size() - 2], i));
            }
            dfs(dfs, i + 1, temp, pos);
            pos.pop_back();
        }
    };

    dfs(dfs, 0, 1, std::vector<int>());
    std::cout << minAns << std::endl;
    std::cout << maxAns << std::endl;
    return 0;
}