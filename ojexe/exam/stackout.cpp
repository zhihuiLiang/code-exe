#include <bits/stdc++.h>

int main() {
    std::string str;
    std::cin >> str;

    int n = str.size();
    const auto travese = [&](auto&& travese, int pos, std::stack<char> sta, std::string seq) -> void {
        if (seq.size() == n) {
            std::cout << seq << std::endl;
            return;
        }
        if (pos < n) {
            auto tmp = sta;
            tmp.push(str[pos]);
            travese(travese, pos + 1, tmp, seq);
        }
        if (!sta.empty()) {
            auto ch = sta.top();
            seq.push_back(ch);
            sta.pop();
            travese(travese, pos, sta, seq);
        }
    };
    travese(travese, 0, {}, {});
    return 0;
}