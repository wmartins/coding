#include "linked_list.hpp"
#include "node.cpp"
#include <iostream>

namespace wmartins {
  template <typename T>
  bool LinkedList<T>::IsEmpty() {
    return this->head == nullptr;
  }

  template <typename T>
  void LinkedList<T>::PushFront(T value) {
    Node<T>* node = new Node<T>(value);

    node->next = this->head;

    this->head = node;

    this->size++;
  }

  template <typename T>
  void LinkedList<T>::PushBack(T value) {
    Node<T>* node = new Node<T>(value);

    if (!this->head) {
      this->head = node;
    } else {
      Node<T>* current = this->head;

      while (current->next) {
        current = current->next;
      }

      current->next = node;
    }

    this->size++;
  }

  template <typename T>
  T LinkedList<T>::ValueAt(int index) {
    if (IsEmpty() || index > this->size) {
      throw std::out_of_range("Item is out of range");
    }

    Node<T>* current = this->head;

    while (index--) {
      current = current->next;
    }

    return current->value;
  }

  template <typename T>
  void LinkedList<T>::RemoveValue(T value) {
    Node<T>* current = this->head;
    Node<T>* prev = nullptr;

    while (current) {
      if (current->value == value) {
        if (prev == nullptr) {
          this->head = current->next;
        } else {
          prev->next = current->next;
        }

        this->size--;

        delete current;
        break;
      }

      prev = current;
      current = current->next;
    }
  }

  template <typename T>
  int LinkedList<T>::GetSize() {
    return this->size;
  }

  template <typename T>
  void LinkedList<T>::InsertAt(int index, T value) {
    if (IsEmpty() || index > this->size) {
      throw std::out_of_range("Item is out of range");
    }

    Node<T>* current = this->head;
    Node<T>* prev = nullptr;
    Node<T>* node = new Node<T>(value);

    while (index--) {
      prev = current;
      current = current->next;
    }

    node->next = current;

    if (prev == nullptr) {
      this->head = node;
    } else {
      prev->next = node;
    }
  }

  template <typename T>
  LinkedList<T> LinkedList<T>::Reverse() {
    LinkedList<T> reversed;

    Node<T>* current = this->head;

    while(current) {
      reversed.PushFront(current->value);

      current = current->next;
    }

    return reversed;
  }

  template <typename T>
  void LinkedList<T>::ToString() {
    Node<T>* current = this->head;

    std::cout << "[ ";
    while (current != nullptr) {
      std::cout << std::to_string(current->value) << " ";

      current = current->next;
    }
    std::cout << "]";

    std::cout << std::endl;
  }
}
