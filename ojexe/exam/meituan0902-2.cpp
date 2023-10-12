#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> strVec;
    std::unordered_set<char> strSet;
    const char* targetStr = "meituan";
    for (int i = 0; i < strlen(targetStr); ++i) {
        strSet.insert(targetStr[i]);
    }
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        bool isNew = true;
        for (char ch : str) {
            if (strSet.count(ch)) {
                if (isNew) {
                    strVec.push_back({ch});
                    isNew = false;
                } else {
                    strVec.back().push_back(ch);
                }
            }
        }
    }

    bool isFind = false;
    int sz = strVec.size();
    const auto dfs = [&](auto&& dfs, int start, std::unordered_set<char> chSet) -> void {
        if (isFind)
            return;
        if (chSet.size() == strlen(targetStr)) {
            isFind = true;
            return;
        }
        if (start >= sz) {
            return;
        }
        for (auto it = chSet.begin(); it != chSet.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::string str = strVec[start];
        for (int i = 0; i < str.size(); ++i) {
            if (!chSet.count(str[i])) {
                chSet.insert(str[i]);
                dfs(dfs, start + 1, chSet);
                chSet.erase(str[i]);
            }
        }
        dfs(dfs, start + 1, chSet);
    };
    dfs(dfs, 0, {});
    std::cout << (isFind ? "YES" : "NO");
    return 0;
}