#pragma once

#include "Task.hpp"
#include "ThreadPool.hpp"

class TaskDispatcher {
public:
  TaskDispatcher() : tp(nullptr) {}
  TaskDispatcher(size_t t) : tp(new ThreadPool(t)) {}
  ~TaskDispatcher() { delete tp; }
  
  void init(size_t t) {
    if (tp)
      delete tp;
    tp = new ThreadPool(t);
  }
  void assign(Task *task) { tp->sumit(task); }

private:
  ThreadPool *tp;
};