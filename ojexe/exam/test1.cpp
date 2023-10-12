#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<char, int>> mylist{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    string intToRoman(int num) {
        int n = 6;
        string res = traverse(num, n);
        return res;
    }

    string traverse(int num, int index) {
        string res = "";
        if (num == 0) {
            cout << index << endl;
            return "";
        }

        auto temp = mylist[index];
        while (num >= temp.second) {
            num -= temp.second;
            res += temp.first;
        }
        if (index != 0 && index % 2 == 0) {
            auto tempLast = mylist[index - 2];
            if (num >= temp.second - tempLast.second) {
                num -= temp.second - tempLast.second;
                res += tempLast.first + temp.first;
            }
        } else if (index % 2 == 1) {
            auto tempLast = mylist[index - 1];
            if (num >= temp.second - tempLast.second) {
                num -= temp.second - tempLast.second;
                res += tempLast.first + temp.first;
            }
        }
        res += traverse(num, index - 1);
        return res;
    }
};

int main() {
    auto ans = Solution().intToRoman(1994);
    std::cout << ans;
    return 0;
}