#include <exception>
#include <iostream>
#include <thread>

using namespace std::literals;

int main() {
    std::thread([] {
        throw std::out_of_range("throw expection");
        while (1) {
            std::cout << "expection" << std::endl;
        }
    }).detach();
    while (1) {
        std::cout << "main" << std::endl;
        std::this_thread::sleep_for(100ms);
    }
}