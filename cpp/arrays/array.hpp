/**
 * This is just a simple implementation of an array data structure for study
 * purposes. It should definitely not be used in any real stuff. Please, use
 * `std::vector`, as advised by the community.
 *
 * It's nice to implement those data structures, as they can teach you so much
 * stuff, from memory management to API design. For example, what should be the
 * return of `Delete`? How can you make sure that you're using your memory
 * wisely?
 */
namespace wmartins {
  template <class T>
  class Array {
    private:
      int size;
      int capacity;
      T* data;
      int Resize(int capacity);

    public:
      Array(int capacity);
      int GetSize();
      int GetCapacity();
      bool IsEmpty();
      T GetAt(int index);
      int Push(T value);
      int Insert(int index, T value);
      int Prepend(T value);
      T Pop();
      T Delete(int index);
      int Remove(T value);
      int Find(T value);
  };
}
