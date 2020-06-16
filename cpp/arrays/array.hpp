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
  class Array {
    private:
      int size;
      int capacity;
      int* data;
      int Resize(int capacity);

    public:
      Array(int capacity);
      int GetSize();
      int GetCapacity();
      bool IsEmpty();
      int GetAt(int index);
      int Push(int value);
      int Insert(int index, int value);
      int Prepend(int value);
      int Pop();
      int Delete(int index);
      int Remove(int value);
      int Find(int value);
  };
}
