#include "node.hpp"

namespace wmartins {
  template <typename T>
  Node<T>::Node(T value) {
    this->value = value;
    this->next = nullptr;
  }
}
