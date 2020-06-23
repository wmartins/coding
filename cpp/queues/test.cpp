#include <iostream>
#include "queue.cpp"
#include "array_queue.cpp"

void test_queue() {
  wmartins::Queue<int>* queue = new wmartins::Queue<int>();

  assert(queue->IsEmpty());

  queue->Enqueue(10);
  queue->Enqueue(66);
  queue->Enqueue(30);

  assert(!queue->IsEmpty());
  assert(queue->Dequeue() == 10);

  queue->Enqueue(54);

  assert(queue->Dequeue() == 66);
  assert(queue->Dequeue() == 30);
  assert(queue->Dequeue() == 54);

  assert(queue->IsEmpty());
}

void test_array_queue() {
  wmartins::ArrayQueue<int>* array_queue = new wmartins::ArrayQueue<int>(5);

  assert(array_queue->IsEmpty());

  array_queue->Enqueue(10);
  array_queue->Enqueue(66);
  array_queue->Enqueue(30);

  assert(!array_queue->IsEmpty());
  assert(array_queue->Dequeue() == 10);

  array_queue->Enqueue(54);

  assert(array_queue->Dequeue() == 66);
  assert(array_queue->Dequeue() == 30);
  assert(array_queue->Dequeue() == 54);

  assert(array_queue->IsEmpty());

  array_queue->Enqueue(37);
  array_queue->Enqueue(88);
  array_queue->Enqueue(90);
  array_queue->Enqueue(120);

  try {
    array_queue->Enqueue(150);
  } catch(const std::length_error* e) {
    std::string expected = "Queue is full";
    assert(expected.compare(e->what()) == 0);
  }

  assert(array_queue->Dequeue() == 37);
  array_queue->Enqueue(150);
}

int main() {
  test_queue();
  test_array_queue();

  std::cout << "All tests passed!" << std::endl;
}
