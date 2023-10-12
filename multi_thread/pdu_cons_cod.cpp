#include <thread>
#include <condition_variable>
#include <random>
#include <chrono>
#include <iostream>

using namespace std::literals;
struct Node
{
    int val;
    Node *next;
    Node() = default;
    Node(int data) : val(data), next(nullptr) {}
};

std::random_device rt;
std::mt19937 gen(rt());
std::uniform_int_distribution<> distr(1, 100);

Node *head = nullptr;

std::mutex list_mutex;
std::condition_variable empty_cv, not_empty_cv;

void proudcer()
{
    while (1)
    {
        auto node = new Node(distr(gen));
        std::unique_lock<std::mutex> lock{list_mutex};
        empty_cv.wait(lock, []
                      { return head == nullptr; });
        node->next = head;
        head = node;
        std::cout << "Thread:" << std::this_thread::get_id() << " produece Node, val = " << node->val << std::endl;
        not_empty_cv.notify_one();
        std::this_thread::sleep_for(5ms);
    }
}

void consumer()
{
    while (1)
    {
        {
            std::unique_lock<std::mutex> lock{list_mutex};
            not_empty_cv.wait(lock, []
                              { return head != nullptr; });
            auto next = head->next;
            std::cout << "Thread:" << std::this_thread::get_id() << " consume Node, val = " << head->val << std::endl;
            delete head;
            head = next;
            empty_cv.notify_one();
            std::this_thread::sleep_for(2ms);
        }
    }
}

int main()
{
    std::thread t1(proudcer), t2(consumer);
    t1.detach();
    t2.detach();
    while (1)
    {
        /* code */
    }

    return 0;
}