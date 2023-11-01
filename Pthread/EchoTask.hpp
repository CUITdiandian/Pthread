#pragma once

#include <iostream>
#include <Windows.h>

#include "Task.hpp"

class EchoTask : public Task {
public:
  EchoTask(int *num) : Task((void *)num){}
  virtual ~EchoTask() {}

  virtual void run() { std::cout << "task run\n" << std::endl;
    int *input = static_cast<int *>(m_data);
    std::cout << "num: " << (*input) << std::endl;
    Sleep(1000);
  }
  virtual void destroy() { std::cout << "task destroy" << std::endl;
    delete this;
  }
};