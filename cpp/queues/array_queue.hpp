#include <sstream>

namespace wmartins {
  template <typename T>
  class ArrayQueue {
    private:
      int capacity;
      int reading_index;
      int writing_index;
      T* list;

    public:
      ArrayQueue(int capacity);
      ~ArrayQueue();
      void Enqueue(T value);
      T Dequeue();
      bool IsEmpty();
      std::string ToString();
  };
}
