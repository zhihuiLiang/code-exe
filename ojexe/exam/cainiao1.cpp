#include <bits/stdc++.h>

int myPow(int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1) {
        return myPow(n - 1) * 2;
    } else {
        int tmp = myPow(n / 2);
        return tmp * tmp;
    }
}

int main() {
    int l, r;
    std::cin >> l >> r;
    int left = (int)std::sqrt(l), right = (int)std::sqrt(r) + 1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (myPow(mid) > r) {
            right = mid - 1;
        } else if (myPow(mid) < l) {
            left = mid + 1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << left - 1 << std::endl;
}