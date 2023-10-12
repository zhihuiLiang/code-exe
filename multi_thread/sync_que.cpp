#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std::literals;

template <typename T>
class SyncQueue {
    int mCap;
    std::queue<T> mQue;
    std::mutex mMutex;
    std::condition_variable mNotEmpty;
    std::condition_variable mNotFull;

public:
    SyncQueue(int cap) : mCap(cap) {
    }

    void product(const T& val) {
        std::unique_lock lock(mMutex);
        mNotFull.wait(lock, [this]() {
            return mQue.size() < mCap;
        });
        mQue.push(val);
        std::cout << "Que Product val : " << val << std::endl;
        mNotEmpty.notify_one();
        std::this_thread::sleep_for(2ms);
    }

    T consume() {
        std::unique_lock lock(mMutex);
        mNotEmpty.wait(lock, [this]() {
            return !mQue.empty();
        });
        auto val = mQue.front();
        std::cout << "Que consume val: " << val << std::endl;
        mQue.pop();
        mNotFull.notify_one();
        std::this_thread::sleep_for(6ms);
        return val;
    }
};

int main() {
    SyncQueue<int> que(2);
    std::thread([&]() {
        for (int i = 0; i < 100; ++i) {
            que.product(i);
        }
    }).detach();
    std::thread([&]() {
        for (int i = 0; i < 100; ++i) {
            que.consume();
        }
    }).detach();
    std::this_thread::sleep_for(60s);
    return 0;
}