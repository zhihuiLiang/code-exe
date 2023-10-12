#include <atomic>
#include <exception>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <thread>
#include <vector>

using namespace std::literals;

template <class T>
class RingQue {
    std::vector<T> que_;
    size_t head_, tail_;
    size_t cap_, size_;
    std::atomic_bool flag;

public:
    RingQue(size_t cap) : cap_(cap) {
        que_.resize(cap);
        size_ = 0;
        head_ = tail_ = 0;
        flag.store(false);
    }

    T top() {
        bool expect = false;
        while (flag.compare_exchange_weak(expect, true)) {
            if (size_ == 0)
                throw std::out_of_range("Ring que is empty!");
            return que_[head_];
        }
        flag.store(false);
    }

    void pop() {
        bool expect = false;
        while (flag.compare_exchange_weak(expect, true)) {
            if (size_ == 0)
                return;
            std::cout << "pop " << que_[head_] << std::endl;
            head_ = (head_ + 1) % cap_;
            size_--;
        }
        flag.store(false);
    }

    void push(T val) {
        bool expect = false;
        while (flag.compare_exchange_weak(expect, true)) {
            que_[tail_] = val;
            tail_ = (tail_ + 1) % cap_;
            if (size_ < cap_) {
                size_++;
            } else {
                head_ = (head_ + 1) % cap_;
            }
            std::cout << "push " << val << std::endl;
        }
        flag.store(false);
    }
};

int main() {
    RingQue<int> rq(10);
    std::thread([&]() {
        for (int i = 1000; i >= 0; --i) {
            rq.push(i);
            std::this_thread::sleep_for(30ms);
        }
    }).detach();

    std::thread([&]() {
        for (int i = 1000; i >= 0; --i) {
            rq.pop();
            std::this_thread::sleep_for(40ms);
        }
    }).detach();

    std::this_thread::sleep_for(1h);
    return 0;
}
