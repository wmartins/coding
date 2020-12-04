#include "array.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace wmartins {
  template <class T>
  Array<T>::Array(int capacity) {
    this->size = 0;
    this->capacity = capacity;

    /**
     * Feel old yet? Where's `malloc` and all that `sizeof` and stuff?
     *
     * https://www.stroustrup.com/bs_faq2.html#malloc
     */
    this->data = new T[capacity];
  }

  /**
   * TODO: maybe change that to something like EnsureCapacity, otherwise,
   * methods calling Resize must specify conditions.
   */
  template <class T>
  int Array<T>::Resize(int capacity) {
    this->capacity = capacity;

    /**
     * Missing `realloc`?
     *
     * https://www.stroustrup.com/bs_faq2.html#renew
     */
    T* data = new T[capacity];
    std::copy(this->data, this->data + this->size, data);
    delete[] this->data;

    this->data = data;

    return 1;
  }

  template <class T>
  int Array<T>::GetSize() {
    return this->size;
  }

  template <class T>
  int Array<T>::GetCapacity() {
    return this->capacity;
  }

  template <class T>
  bool Array<T>::IsEmpty() {
    return this->size == 0;
  }

  template <class T>
  T Array<T>::GetAt(int index) {
    return this->data[index];
  }

  template <class T>
  int Array<T>::Push(T value) {
    Insert(this->size, value);

    return this->size - 1;
  }

  template <class T>
  int Array<T>::Insert(int index, T value) {
    if (index > this->size) {
      throw std::out_of_range("Index out of range");
    }

    if (this->size + 1 > this->capacity) {
      Resize(this->capacity * 2);
    }

    std::copy(
      this->data + index,
      this->data + this->size,
      this->data + index + 1
    );

    this->data[index] = value;

    this->size++;

    return 1;
  }

  template <class T>
  int Array<T>::Prepend(T value) {
    /**
     * Array:   [ 10, 33, 45, 7, 12, _, _, _ ]
     * Moves:   [ _, 10, 33, 45, 7, 12, _, _ ]
     * Inserts: [ V, 10, 33, 45, 7, 12, _, _ ]
     */
    if (this->size + 1 > this->capacity) {
      Resize(this->capacity * 2);
    }

    Insert(0, value);

    return 1;
  }

  template <class T>
  T Array<T>::Pop() {
    return Delete(this->size - 1);
  }

  template <class T>
  T Array<T>::Delete(int index) {
    if (index > this->size - 1) {
      throw std::out_of_range("Index out of range");
    }

    T current = GetAt(index);
    /**
     * Index: 2
     * Array:   [ 10, 33, 45, 7, 12, _, _, _ ]
     * Copy:    [ 10, 33, 45, 7, 12, _, _, _ ]
     *                        ^^
     * Move:    [ 10, 33, 7, 12, _, _, _, _ ]
     */
    std::copy(
      this->data + index + 1,
      this->data + this->size,
      this->data + index
    );

    this->size--;

    // When size reaches 1/4 of the capacity, reduces capacity by half
    if (this->size == this->capacity / 4) {
      Resize(this->capacity / 2);
    }

    return current;
  }

  template <class T>
  int Array<T>::Find(T value) {
    for (int i = 0; i < this->size; i++) {
      if (this->data[i] == value) {
        return i;
      }
    }

    return -1;
  }
}
