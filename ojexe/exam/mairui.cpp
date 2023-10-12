#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string str;
    while (std::cin >> str) {
        // bool isVaild = true;
        // int num = 0;
        // for (int i = 0; i < str.size(); ++i) {
        //     if (str[i] != '0' && str[i] != '1') {
        //         isVaild = false;
        //         std::cerr << "Invail input!" << std::endl;
        //         break;
        //     }
        //     num *= 2;
        //     num += str[i] - '0';
        // }
        // if (isVaild) {
        //     std::cout << num << std::endl;
        //     break;
        // }
        bool isValid = true;
        std::string ans;
        int len = str.size();
        for (int i = len - 1; i >= 0; i -= 4) {
            int num = 0;
            int j = i - 3 >= 0 ? i - 3 : 0;
            for (; j <= i; ++j) {
                if (str[j] != '0' && str[j] != '1') {
                    isValid = false;
                    std::cerr << "Invaild input!" << std::endl;
                    break;
                }
                num *= 2;
                num += str[j] - '0';
            }
            if (!isValid)
                break;
            if (num >= 10) {
                ans.push_back('A' + num - 10);
            } else {
                ans.push_back('0' + num);
            }
        }
        if (isValid) {
            std::reverse(ans.begin(), ans.end());
            std::cout
                << ans << std::endl;
            break;
        }
    }

    return 0;
}