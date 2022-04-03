// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
template <typename type, int size>
class TStack {
 private:
  type arr[100];
  int top;
 public:
  TStack() : top(-1) {}
  type get() const { return arr[top]; }
  bool isEmpty() const { return top == -1; }
  bool isFull() const { return top == size - 1; }
  void pop() {
    if (top >= 0) top--;
  }
  void push(type item) {
    if (top < size - 1) arr[++top] = item;
  }
};
#endif
