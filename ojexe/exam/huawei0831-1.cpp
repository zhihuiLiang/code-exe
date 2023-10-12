#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<int> vec(n);
    for (int i = 0; i < vec.size(); ++i) {
        std::cin >> vec[i];
    }

    std::vector<int> ans(1);
    int numPerDepth = 1, idx = 0;
    while (numPerDepth <= n) {
        for (int i = 0; i < numPerDepth; ++i) {
            int start = i * (n / numPerDepth);
            int max = vec[start], min = vec[start];
            for (int j = 0; j < n / numPerDepth; ++j) {
                if (vec[start + j] > max) {
                    max = vec[start + j];
                }
                if (vec[start + j] < min) {
                    min = vec[start + j];
                }
            }
            // std::cout << "max: " << max << " min: " << min << std::endl;
            idx++;
            int sumParent = 0, pIdx = idx / 2;
            while (pIdx > 0) {
                sumParent += ans[pIdx];
                pIdx /= 2;
            }
            // std::cout << "sumParent: " << sumParent << std::endl;
            ans.push_back((max + min) / 2 - sumParent);
        }
        numPerDepth *= 2;
    }

    for (int i = 1; i < ans.size(); ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}