#include "array.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace wmartins {
  Array::Array(int capacity) {
    this->size = 0;
    this->capacity = capacity;

    /**
     * Feel old yet? Where's `malloc` and all that `sizeof` and stuff?
     *
     * https://www.stroustrup.com/bs_faq2.html#malloc
     */
    this->data = new int[capacity];
  }

  /**
   * TODO: maybe change that to something like EnsureCapacity, otherwise,
   * methods calling Resize must specify conditions.
   */
  int Array::Resize(int capacity) {
    this->capacity = capacity;

    /**
     * Missing `realloc`?
     *
     * https://www.stroustrup.com/bs_faq2.html#renew
     */
    int* data = new int[capacity];
    std::copy(this->data, this->data + this->size, data);
    delete[] this->data;

    this->data = data;

    return 1;
  }

  int Array::GetSize() {
    return this->size;
  }

  int Array::GetCapacity() {
    return this->capacity;
  }

  bool Array::IsEmpty() {
    return this->size == 0;
  }

  int Array::GetAt(int index) {
    return this->data[index];
  }

  int Array::Push(int value) {
    Insert(this->size, value);

    return this->size - 1;
  }

  int Array::Insert(int index, int value) {
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

  int Array::Prepend(int value) {
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

  int Array::Pop() {
    return Delete(this->size - 1);
  }

  int Array::Delete(int index) {
    if (index > this->size - 1) {
      throw std::out_of_range("Index out of range");
    }

    int current = GetAt(index);
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

  int Array::Find(int value) {
    for (int i = 0; i < this->size; i++) {
      if (this->data[i] == value) {
        return i;
      }
    }

    return -1;
  }
}
