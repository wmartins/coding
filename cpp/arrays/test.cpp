#include <iostream>
#include "array.cpp"

class Node {
public:
  bool operator==(const Node &other) const {
    return this->value == other.value;
  };

  int value;

  Node() {
  }

  Node(int value) {
    this->value = value;
  };
};

int main() {
  wmartins::Array<Node> array(2);

  assert(array.GetCapacity() == 2);
  assert(array.GetSize() == 0);
  assert(array.IsEmpty());

  // Push
  assert(array.Push(Node(10)) == 0);
  assert(array.Push(Node(50)) == 1);
  assert(array.GetCapacity() == 2);
  assert(array.Push(Node(30)) == 2);
  assert(array.GetCapacity() == 4);
  // [10, 50, 30]

  // GetSize
  assert(array.GetSize() == 3);

  // GetAt
  assert(array.GetAt(1).value == 50);

  // Insert
  assert(array.Insert(2, Node(60)));
  assert(array.GetAt(0).value == 10);
  assert(array.GetAt(1).value == 50);
  assert(array.GetAt(2).value == 60);
  assert(array.GetAt(3).value == 30);
  // [10, 50, 60, 30]

  // Prepend
  assert(array.Prepend(Node(88)) == 1); // TODO: return something better than 1?
  // [88, 10, 50, 60, 30]
  std::cout << array.GetAt(0).value << std::endl;
  assert(array.GetAt(0).value == 88);
  assert(array.GetAt(1).value == 10);
  assert(array.GetAt(2).value == 50);
  assert(array.GetAt(3).value == 60);
  assert(array.GetAt(4).value == 30);

  // Pop
  assert(array.GetSize() == 5);
  assert(array.Pop().value == 30);
  assert(array.GetSize() == 4);
  // [88, 10, 50, 60]

  // Delete
  assert(array.Delete(1).value == 10);
  assert(array.GetAt(0).value == 88);
  assert(array.GetAt(1).value == 50);
  assert(array.GetSize() == 3);
  // [88, 50, 60]

  // Find
  assert(array.Push(Node(18)));
  assert(array.Push(Node(37)));
  assert(array.Push(Node(22)));
  assert(array.Push(Node(93)));
  assert(array.Find(Node(37)) == 4);
  assert(array.Find(Node(93)) == 6);
  // [88, 50, 60, 18, 37, 22, 93]
  
  // Resize
  assert(array.GetCapacity() == 8);
  std::cout << "Find" << std::endl;
  assert(array.Delete(array.Find(Node(22))) == 22);
  assert(array.Find(Node(22)) == -1);
  assert(array.Pop().value == 93);
  assert(array.Pop().value == 37);
  assert(array.GetCapacity() == 8);
  assert(array.Pop().value == 18);
  assert(array.Pop().value == 60);
  assert(array.GetCapacity() == 4);

  // Exceptions
  try {
    array.Insert(100, Node(10));
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
