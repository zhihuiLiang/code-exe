#include <thread>
#include <mutex>
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

void proudcer()
{
    while (1)
    {
        auto node = new Node(distr(gen));
        {
            std::lock_guard lock{list_mutex};
            node->next = head;
            head = node;
            std::cout << "Thread:" << std::this_thread::get_id() << " produece Node, val = " << node->val << std::endl;
        }
        std::this_thread::sleep_for(5ms);
    }
}

void consumer()
{
    while (1)
    {
        {
            std::lock_guard lock{list_mutex};
            if (head)
            {
                auto next = head->next;
                std::cout << "Thread:" << std::this_thread::get_id() << " consume Node, val = " << head->val << std::endl;
                delete head;
                head = next;
            }
            std::this_thread::sleep_for(2ms);
        }
    }
}

int main()
{
    constexpr int proudcer_size = 5, consumer_size = 3;
    std::thread p[proudcer_size], c[consumer_size];
    for (int i = 0; i < consumer_size; ++i)
    {
        p[i] = std::thread(proudcer);
        p[i].detach();
    }
    for (int i = 0; i < 3; ++i)
    {
        c[i] = std::thread(consumer);
        c[i].detach();
    }
    while (1)
    {
        /* code */
    }

    return 0;
}