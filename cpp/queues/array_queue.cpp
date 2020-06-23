#include "array_queue.hpp"
#include <stdexcept>

namespace wmartins {
  template <typename T>
  ArrayQueue<T>::ArrayQueue(int capacity) {
    this->capacity = capacity;
    this->reading_index = 0;
    this->writing_index = 0;
    this->list = new T[capacity]();
  }

  template <typename T>
  ArrayQueue<T>::~ArrayQueue() {
    delete[] this->list;
  }

  template <typename T>
  void ArrayQueue<T>::Enqueue(T value) {
    int next_writing_index = (this->writing_index + 1) % this->capacity;

    if (next_writing_index == this->reading_index) {
      throw new std::length_error("Queue is full");
    }

    this->list[this->writing_index] = value;
    this->writing_index = next_writing_index;
  }

  template <typename T>
  T ArrayQueue<T>::Dequeue() {
    if (this->IsEmpty()) {
      throw new std::length_error("Queue is empty");
    }

    int next_reading_index = (this->reading_index + 1) % this->capacity;

    T value = this->list[this->reading_index];
    this->reading_index = next_reading_index;

    return value;
  }

  template <typename T>
  bool ArrayQueue<T>::IsEmpty() {
    return this->reading_index == this->writing_index;
  }

  template <typename T>
  std::string ArrayQueue<T>::ToString() {
    std::stringstream to_string;

    to_string << "Capacity: " << this->capacity << std::endl;
    to_string << "Writing Index: " << this->writing_index << std::endl;
    to_string << "Reading Index: " << this->reading_index << std::endl;
    to_string << "Array: [ ";

    for (int i = 0; i < capacity; i += 1) {
      to_string << this->list[i] << " ";
    }

    to_string << "]";

    return to_string.str();
  }
}
