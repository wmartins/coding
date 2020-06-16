#include <iostream>
#include "array.cpp"

int main() {
  wmartins::Array array(2);

  assert(array.GetCapacity() == 2);
  assert(array.GetSize() == 0);
  assert(array.IsEmpty());

  // Push
  assert(array.Push(10) == 0);
  assert(array.Push(50) == 1);
  assert(array.GetCapacity() == 2);
  assert(array.Push(30) == 2);
  assert(array.GetCapacity() == 4);
  // [10, 50, 30]

  // GetSize
  assert(array.GetSize() == 3);

  // GetAt
  assert(array.GetAt(1) == 50);

  // Insert
  assert(array.Insert(2, 60));
  assert(array.GetAt(0) == 10);
  assert(array.GetAt(1) == 50);
  assert(array.GetAt(2) == 60);
  assert(array.GetAt(3) == 30);
  // [10, 50, 60, 30]

  // Prepend
  assert(array.Prepend(88) == 1); // TODO: return something better than 1?
  // [88, 10, 50, 60, 30]
  assert(array.GetAt(0) == 88);
  assert(array.GetAt(1) == 10);
  assert(array.GetAt(2) == 50);
  assert(array.GetAt(3) == 60);
  assert(array.GetAt(4) == 30);

  // Pop
  assert(array.GetSize() == 5);
  assert(array.Pop() == 30);
  assert(array.GetSize() == 4);
  // [88, 10, 50, 60]

  // Delete
  assert(array.Delete(1) == 10);
  assert(array.GetAt(0) == 88);
  assert(array.GetAt(1) == 50);
  assert(array.GetSize() == 3);
  // [88, 50, 60]

  // Find
  assert(array.Push(18));
  assert(array.Push(37));
  assert(array.Push(22));
  assert(array.Push(93));
  assert(array.Find(37) == 4);
  assert(array.Find(93) == 6);
  // [88, 50, 60, 18, 37, 22, 93]
  
  // Resize
  assert(array.GetCapacity() == 8);
  assert(array.Delete(array.Find(22)));
  assert(array.Find(22) == -1);
  assert(array.Pop() == 93);
  assert(array.Pop() == 37);
  assert(array.GetCapacity() == 8);
  assert(array.Pop() == 18);
  assert(array.Pop() == 60);
  assert(array.GetCapacity() == 4);

  // Exceptions
  try {
    array.Insert(100, 10);
  } catch(const std::out_of_range& e){
    std::string expected = "Index out of range";
    assert(expected.compare(e.what()) == 0);
  }

  try {
    array.Delete(500);
  } catch(const std::out_of_range& e){
    std::string expected = "Index out of range";
    assert(expected.compare(e.what()) == 0);
  }

  std::cout << "All tests passing!" << std::endl;
}
