#pragma once
#include "ThreadPool.h"
#include <utility> // for std::forward

template<class F>
void ThreadPool::enqueue(F&& task) {
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        tasks.emplace(std::forward<F>(task));
    }
    condition.notify_one();
}
