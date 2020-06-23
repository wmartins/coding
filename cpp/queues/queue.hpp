#include <list>

namespace wmartins {
  template <typename T>
  class Queue {
    private:
      std::list<T>* list;

    public:
      Queue();
      void Enqueue(T value);
      T Dequeue();
      bool IsEmpty();
  };
}
