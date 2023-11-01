#include <iostream>
#include "Singleton.hpp"
#include "EchoTask.hpp"
#include "TaskDispatcher.hpp"
#include <Windows.h>

int main() { size_t threads = 8;
  Singleton<TaskDispatcher>::instance()->init(threads);

  for (int i = 0; i < 10; ++i) {
    int *num = new int;
    *num = i;
    Task *task = new EchoTask(num);
    Singleton<TaskDispatcher>::instance()->assign(task);
  }

  Sleep(3000);
  return 0;
}