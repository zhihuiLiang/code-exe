#include <bits/stdc++.h>

class String {
public:
    String(const char* cstr) { std::cout << "String()" << std::endl; }

    // 1
    String(const String& v) { std::cout << "String(const String& v)" << std::endl; }

    // 2
    String(const String&& v) noexcept { std::cout << "String(const String&& v)" << std::endl; }

    // 3
    String& operator=(const String& v) {
        std::cout << "String& operator=(const String& v)" << std::endl;
        return *this;
    }
};

void test(int i, String const& s) {
    std::cout << "test " << i << ":" << std::endl;
}

int main() {
    while (1) {
        String s("hello");
        std::cout << "----------------" << std::endl;

        // 输出 1, 2
        std::thread t1(test, 1, s);
        t1.join();
        std::cout << "----------------" << std::endl;

        // 输出 2, 2
        std::thread t2(test, 2, std::move(s));
        t2.join();
        std::cout << "----------------" << std::endl;

        // 只输出 1
        std::thread t3(test, 3, "hello");
        t3.join();
        std::cout << "----------------" << std::endl;

        // 无输出
        std::thread t4(test, 4, std::ref(s));
        std::cout << "----------------" << std::endl;
        t4.join();
    }
}