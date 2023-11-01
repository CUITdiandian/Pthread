#pragma once

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>
#include <type_traits>

#include "Task.hpp"

class ThreadPool {
public:
  ThreadPool(size_t threads = 0);
  void sumit(Task *task);
  ~ThreadPool();

private:
  std::vector<std::thread> workers;
  std::queue<Task *> tasks;
  
  std::mutex queue_mutex;
  std::condition_variable condition;
  bool stop;
};
