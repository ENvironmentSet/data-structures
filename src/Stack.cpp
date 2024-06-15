#include "Node.h"
#include <initializer_list>
#include <exception>
#include <new>

class EmptyStack: public std::exception {
public:
  const char *what() const noexcept {
    return "Stack is empty";
  }
};

template <typename T>
class Stack {
  Node<T> *top = nullptr;

public:
  Stack(std::initializer_list<T> items) {
    for (T item: items)
      Push(item);
  }
  Stack() {}

  ~Stack() {
    MakeEmpty();
  }

  void MakeEmpty() {
    while (top != nullptr) {
      Node<T>* target = top;
      top = top->next;

      delete target;
    }
  }

  bool IsFull() {
    try {
      delete new Node<T>(T());

      return true;
    } catch (std::bad_alloc &e) {
      return false;
    }
  }

  bool IsEmpty() {
    return top == nullptr;
  }

  void Push(T item) {
    top = new Node<T>(item, top);
  }

  void Pop(T &item) {
    if (IsEmpty()) throw EmptyStack();
    
    item = top->item;
    top = top->next;
  }

  T Top() {
    if (IsEmpty()) throw EmptyStack();
    else return top->item;
  }
};