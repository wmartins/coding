#include "queue.hpp"

namespace wmartins {
  template <typename T>
  Queue<T>::Queue() {
    this->list = new std::list<T>;
  }

  template <typename T>
  bool Queue<T>::IsEmpty() {
    return this->list->empty();
  }

  template <typename T>
  void Queue<T>::Enqueue(T value) {
    this->list->push_back(value);
  }

  template <typename T>
  T Queue<T>::Dequeue() {
    T value = this->list->front();
    this->list->pop_front();

    return value;
  }
}
