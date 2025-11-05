#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>
class ThreadPool {
public:
    explicit ThreadPool(int numThreads);
    ~ThreadPool();
    template<class F>
    void enqueue(F&& task);
        int size() const;
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    std::atomic<bool> stop;
};
#include "ThreadPool.inl"
#endif
