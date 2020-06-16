# Linked Lists

My attempt on creating a custom Linked List using C++

## Methods

- `IsEmpty()`: checks if the list is empty
- `PushFront()`: inserts an element to the front of the list
- `PushBack()`: inserts an element to the back of the list
- `ValueAt()`: gets element at specified `index`
- `RemoveValue()`: removes the first value found specified by `value`
- `InsertAt()`: inserts at `index` the specified `value`
- `ToString()`: prints a user friendly representation of the list
- `Reverse()`: reverses the list

## Comments

Right now, I've developed linked lists using only a `head` pointer, which is
correct and works, however, it may not be the best way to do it when thinking
about performance. For example, `PushBack` right now is a `O(n)` operation,
because I have to traverse the entire list to add at the end. Using a `tail`
pointer could help with that.

There's one interesting thing about performance and the method `RemoveValue`,
because it will always be `O(n)`, as the `Node` always point to the next
element, and not to the previous one. So, implementing something like a Doubly
Linked List could help with that.
