#include <iostream>
#include "linked_list.cpp"

int main() {
  wmartins::LinkedList<int> linked_list;

  assert(linked_list.IsEmpty());
  linked_list.PushFront(73);
  assert(!linked_list.IsEmpty());

  linked_list.PushFront(44);
  assert(linked_list.ValueAt(0) == 44);
  linked_list.PushFront(39);
  assert(linked_list.ValueAt(0) == 39);
  assert(linked_list.ValueAt(1) == 44);
  linked_list.PushBack(55);
  assert(linked_list.ValueAt(0) == 39);
  assert(linked_list.ValueAt(3) == 55);

  assert(linked_list.GetSize() == 4);
  linked_list.RemoveValue(44);
  assert(linked_list.GetSize() == 3);

  linked_list.InsertAt(0, 97);
  assert(linked_list.ValueAt(0) == 97);
  linked_list.InsertAt(2, 66);
  assert(linked_list.ValueAt(2) == 66);

  linked_list.ToString();

  wmartins::LinkedList<int> reversed = linked_list.Reverse();

  reversed.ToString();

  std::cout << "All tests passed!" << std::endl;
}
