#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> wordList) {
        std::unordered_set<std::string> wordSet;
        for (auto str : wordList) {
            wordSet.insert(str);
        }
        if (!wordSet.count(endWord)) {
            return 0;
        }
        int n = wordList.size() + 1;
        int dstIdx = 0;
        std::vector<std::vector<int>> adjMap(n);
        for (int i = 0; i < wordList.size(); ++i) {
            const auto canConvert = [](std::string str1, std::string str2) {
                int cnt = 0;
                if (str1.size() != str2.size()) {
                    return false;
                }
                for (int i = 0; i < str1.size(); ++i) {
                    if (str1[i] != str2[i]) {
                        ++cnt;
                    }
                }
                return cnt == 1;
            };
            if (canConvert(beginWord, wordList[i])) {
                adjMap[0].push_back(i + 1);
            }
            if (wordList[i] == endWord) {
                dstIdx = i + 1;
            }
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (canConvert(wordList[i], wordList[j])) {
                    adjMap[i + 1].push_back(j + 1);
                    adjMap[j + 1].push_back(i + 1);
                }
            }
        }

        std::queue<std::pair<int, int>> qStart, qEnd;
        qStart.emplace(0, 1);
        qEnd.emplace(dstIdx, 1);

        while (!qStart.empty() && !qEnd.empty()) {
            auto topStart = qStart.front();
            qStart.pop();
            auto topEnd = qEnd.front();
            qEnd.pop();

            for (auto to : adjMap[topStart.first]) {
                if (to == topEnd.first) {
                    return topStart.second + topEnd.second;
                }
                if (wordSet.count(wordList[to - 1])) {
                    qStart.emplace(to, topStart.second + 1);
                    wordSet.erase(wordList[to - 1]);
                }
            }

            for (auto to : adjMap[topEnd.first]) {
                if (to == topStart.first) {
                    return topStart.second + topEnd.second;
                }
                if (wordSet.count(wordList[to - 1])) {
                    qEnd.emplace(to, topEnd.second + 1);
                    wordSet.erase(wordList[to - 1]);
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution().ladderLength("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
}