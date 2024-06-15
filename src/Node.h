#pragma once

template <typename T>
struct Node {
  T item;
  Node *next;

  Node(T item): item(item), next(nullptr) {}
  Node(T item, Node *next): item(item), next(next) {}
};