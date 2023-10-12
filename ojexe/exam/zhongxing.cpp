#include <bits/stdc++.h>

int main() {
    std::vector<int> nums;
    int n;
    while (std::cin >> n) {
        nums.push_back(n);
    }
    if (nums.size() == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    if (nums.size() == 1) {
        std::cout << nums[0] << std::endl;
        return 0;
    }
    int steal = 0, noSteal = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        int tmp = steal;
        steal = std::max(steal, noSteal + nums[i]);
        noSteal = tmp;
    }
    int ans1 = std::max(steal, noSteal);
    steal = 0, noSteal = 0;
    for (int i = 1; i < nums.size(); ++i) {
        int tmp = steal;
        steal = std::max(steal, noSteal + nums[i]);
        noSteal = tmp;
    }
    std::cout << std::max({ans1, steal, noSteal}) << std::endl;
    return 0;
}