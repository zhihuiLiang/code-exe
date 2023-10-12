#include <mutex>
#include <thread>
#include <iostream>

using namespace std::literals;

constexpr size_t philosopher_num = 5;
std::mutex chop_mutex[philosopher_num];

void primalPhilosopher(int index)
{
    while (1)
    {
        {
            std::lock_guard lock1{chop_mutex[index]};
            std::lock_guard lock2{chop_mutex[(index + 1) % philosopher_num]};
            std::cout << "philosopher:" << index << " is eating for 2ms" << std::endl;
            std::this_thread::sleep_for(2ms);
        }
        std::cout << "philosopher:" << index << " is thinking" << std::endl;
        std::this_thread::sleep_for(3ms);
    }
}

void sln1Philosopher(int index)
{
    while (1)
    {
        if (index % 2 == 1)
        {
            std::lock_guard lock1{chop_mutex[index]};
            std::lock_guard lock2{chop_mutex[(index + 1) % philosopher_num]};
            std::cout << "philosopher:" << index << " is eating for 2ms" << std::endl;
            std::this_thread::sleep_for(2ms);
        }
        else
        {
            std::lock_guard lock1{chop_mutex[(index + 1) % philosopher_num]};
            std::lock_guard lock2{chop_mutex[index]};
            std::cout << "philosopher:" << index << " is eating for 2ms" << std::endl;
            std::this_thread::sleep_for(2ms);
        }
        std::cout << "philosopher:" << index << " is thinking" << std::endl;
        std::this_thread::sleep_for(3ms);
    }
}

void sln2Philosopher(int index)
{

    while (1)
    {
        {
            std::unique_lock lock1{chop_mutex[index], std::defer_lock};
            std::unique_lock lock2{chop_mutex[(index + 1) % philosopher_num], std::defer_lock};
            std::lock(lock1, lock2);
            std::cout << "philosopher:" << index << " is eating for 2ms" << std::endl;
            //std::this_thread::sleep_for(2ms);
        }
        std::cout << "philosopher:" << index << " is thinking" << std::endl;
        //std::this_thread::sleep_for(3ms);
    }
}

int main()
{
    for (int i = 0; i < philosopher_num; ++i)
    {
        std::thread t(sln2Philosopher, i);
        t.detach();
    }
    while (1)
        ;
    return 0;
}