#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

class ThreadPool {
    size_t t_size_, q_size_;

    std::vector<std::thread> threads_;
    std::queue<std::function<void()>> task_queue_;

    std::mutex pool_mutex_;
    std::condition_variable not_empty_;
    std::condition_variable not_full_;

    bool is_shutdown_;

public:
    ThreadPool(size_t t_size, size_t q_size) : t_size_(t_size), q_size_(q_size), is_shutdown_(false) {
        threads_.reserve(t_size_);

        for (int i = 0; i < t_size_; ++i) {
            threads_.emplace_back([this] {
                while (1) {
                    std::unique_lock lock{pool_mutex_};
                    not_empty_.wait(lock, [this] { return !task_queue_.empty() || is_shutdown_; });
                    if (is_shutdown_)
                        return;
                    auto task = task_queue_.front();
                    task_queue_.pop();
                    lock.unlock();

                    not_full_.notify_one();
                    task();
                }
            });
        }
    }

    template <class F, class... Args>
    auto addTask(F &&f, Args &&...args) -> std::future<typename std::result_of<F(Args...)>::type> {
        using ret_type = typename std::result_of<F(Args...)>::type;
        auto task_ptr = std::make_shared<std::packaged_task<ret_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        auto fut = task_ptr->get_future();

        std::unique_lock lock{pool_mutex_};
        not_full_.wait(lock, [this]() { return is_shutdown_ || task_queue_.size() != q_size_; });
        if (is_shutdown_) {
            throw std::runtime_error("Thread Pool is shutdown! Do not add task!");
        }
        task_queue_.emplace([task_ptr] { (*task_ptr)(); });
        not_empty_.notify_one();
        return fut;
    }

    ~ThreadPool() {
        {
            std::unique_lock lock{pool_mutex_};
            is_shutdown_ = true;
        }
        not_empty_.notify_all();
        for (auto &&thread : threads_) {
            thread.join();
        }
    }
};