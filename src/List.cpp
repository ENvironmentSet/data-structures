#include <initializer_list>
#include <iterator>
#include <new>
#include "Node.h"

template <typename T>
class UnsortedList {
protected:
  Node<T>* head = nullptr;
  int length = 0;
  int cursor = -1;

public:
  UnsortedList(std::initializer_list<T> items) {
    for(auto iter = std::rbegin(items); iter != std::rend(items); iter++)
      InsertItem(*iter);
  }
  UnsortedList() {}

  virtual ~UnsortedList() {
    while(head != nullptr) {
      Node<T>* temp = head;
      head = head->next;

      delete temp;
    }
  }

  bool IsFull() {
    try {
      Node<T>* item = new Node<T>(T());

      delete item;

      return false;
    } catch (std::bad_alloc &e) {
      return true;
    }
  }

  int LengthIs() {
    return length;
  }

  void RetrieveItem(T &item, bool &found) {
    Node<T>* target = head;

    while (target != nullptr && target->item != item)
      target = target->next;
    
    if (target == nullptr) {
      found = false;
    } else {
      item = target->item;
      found = true;
    }
  }

  void InsertItem(T item) {
    head = new Node<T>(item, head);
    length++;
  }

  void DeleteItem(T item) {
    Node<T>* prev = nullptr;
    Node<T>* target = head;

    while (target != nullptr) {
      if (target->item == item) {
        if (prev != nullptr)
          prev->next = target->next;
        else 
          head = target->next;
        
        delete target;
        length--;
        break;
      }
      
      prev = target;
      target = target->next;
    }
  }

  void ResetList() {
    cursor = -1;
  }

  void GetNextItem(T &item) {
    if (cursor + 1 >= length) return;
    
    cursor++;

    Node<T>* target = head;

    for (int i = 0; i < cursor; i++)
      target = target->next;
    
    item = target->item;
  }
};

template <typename T>
class SortedList: public UnsortedList<T> {
public:
  SortedList(std::initializer_list<T> items) {
    for(T item: items)
      InsertItem(item);
  }
  SortedList() {}

  ~SortedList() {}

  void InsertItem(T item) {
    Node<T>* prev = nullptr;
    Node<T>* current = this->head;

    while (current != nullptr && current->item > item) {
      prev = current;
      current = current->next;
    }

    if (prev == nullptr) {
      this->head = new Node<T>(item, current);
    } else {
      prev->next = new Node<T>(item, current);
    }

    this->length++;
  }
};
