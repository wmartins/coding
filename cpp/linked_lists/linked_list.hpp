#include "node.hpp"

namespace wmartins {
  template <typename T>
  class LinkedList {
    public:
      LinkedList<T>() {
        this->head = nullptr;
      }

      bool IsEmpty();
      void PushFront(T value);
      void PushBack(T value);
      T ValueAt(int index);
      void RemoveValue(T value);
      int GetSize();
      void InsertAt(int index, T value);
      void ToString();
      LinkedList<T> Reverse();

    private:
      int size;
      Node<T>* head;
  };
}
