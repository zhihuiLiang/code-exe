#include <iostream>
#include <vector>
#include <chrono>

#include "threadpool.hpp"

int main()
{

    ThreadPool pool(4, 10);
    std::vector<std::future<int>> results;

    for (int i = 0; i < 8; ++i)
    {
        results.emplace_back(
            pool.addTask([i]
                         {
                             std::cout << "thread:" << std::this_thread::get_id() << std::endl;
                             std::cout << "hello " << i << std::endl;
                             std::this_thread::sleep_for(std::chrono::seconds(1));
                             std::cout << "world " << i << std::endl;
                             return i * i;
                         }));
    }

    for (auto &&result : results)
        std::cout << "Res:" << result.get() << ' ';
    std::cout << std::endl;

    return 0;
}