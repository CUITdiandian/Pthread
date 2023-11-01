#pragma once
#include "Task.hpp"

template <class T> class Singleton {
private:
  Singleton(){};
  ~Singleton(){};

public:
  static T *instance();
  void assign(Task *task);
};

template <class T> inline T *Singleton<T>::instance() {
  static T t(0);
  return &t;
}

template <class T> inline void Singleton<T>::assign(Task *task) {
  instance()->assign(task);
}
