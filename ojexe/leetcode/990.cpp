#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(const vector<string>& deadends, string target) {
        std::unordered_set<std::string> deadendsMap;
        std::unordered_set<std::string> usedSet;

        usedSet.insert("0000");
        for (int i = 0; i < deadends.size(); ++i) {
            deadendsMap.insert(deadends[i]);
        }
        if (deadendsMap.count("0000")) {
            return -1;
        }

        std::queue<std::pair<std::string, int>> que;
        que.push({"0000", 0});

        while (!que.empty()) {
            auto top = que.front();
            que.pop();

            if (top.first == target) {
                return top.second;
            }

            std::cout << "top first " << top.first << " " << top.second << std::endl;
            for (int i = 0; i < 4; ++i) {
                std::string nextStr = top.first;
                int ch = top.first[i] - '0' + 1;
                nextStr[i] = ch % 10 + '0';
                if (deadendsMap.count(nextStr))
                    continue;
                if (usedSet.count(nextStr))
                    continue;
                // std::cout << nextStr << std::endl;
                que.push({nextStr, top.second + 1});
                usedSet.insert(nextStr);
                ch = top.first[i] - '0' - 1;
                if (ch < 0) {
                    ch = 9;
                }
                nextStr[i] = ch + '0';
                if (deadendsMap.count(nextStr))
                    continue;
                if (usedSet.count(nextStr))
                    continue;
                // std::cout << nextStr << std::endl;
                que.push({nextStr, top.second + 1});
                usedSet.insert(nextStr);
            }
        }
        return -1;
    }
};

int main() {
    Solution().openLock({"9999"}, "9998");
}