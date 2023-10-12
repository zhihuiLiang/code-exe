#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string str;
    std::cin >> str;

    int n = str.size();

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'o' && str.substr(i, 4) == "oppo") {
            sum += (i + 1) * (n - i - 3);
        }
    }
    std::cout << sum << std::endl;
    return 0;
}