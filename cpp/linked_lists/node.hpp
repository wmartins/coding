#ifndef NODE_HPP
#define NODE_HPP
namespace wmartins {
  template <typename T>
  class Node {
    public:
      T value;
      Node* next;

      Node(T value);
  };
}
#endif
