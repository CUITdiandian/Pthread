#pragma once

#include <mutex>
#include <future>

class Task {
public:
  Task() : m_data(nullptr) {}
  Task(void *data) : m_data(data) {}
  virtual ~Task() {
    if (m_data)
      delete m_data;
  }

  void *get_data() { return m_data; }
  void set_data(void *data) {
    if (m_data)
      delete m_data;
    m_data = data;
  }

  virtual void run() = 0;
  virtual void destroy() = 0;

protected:
  void *m_data;
};