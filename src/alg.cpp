// Copyright 2021 NNTU-CS
#include <iostream>
#include <map>
#include <string>
#include "tstack.h"
int priority(char op) {
  switch (op) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '-':
      return 2;
    case '+':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
    case ' ':
      return 5;
    default:
      return 4;
  }
}
std::string infx2pstfx(std::string inf) {
  std::string result;
  char space = ' ';
  TStack<char, 100> stack;
  for (int i = 0; i < inf.size(); i++) {
    if (priority(inf[i]) == 4) {
      result.push_back(inf[i]);
      result.push_back(space);
    } else {
      if (priority(inf[i]) == 0) {
        stack.push(inf[i]);
      } else if (stack.isEmpty()) {
        stack.push(inf[i]);
      } else if ((priority(inf[i]) > priority(stack.get()))) {
        stack.push(inf[i]);
      } else if (priority(inf[i]) == 1) {
        while (priority(stack.get()) != 0) {
          result.push_back(stack.get());
          result.push_back(space);
          stack.pop();
        }
        stack.pop();
      } else {
        char a = priority(inf[i]);
        char b = priority(stack.get());
        while ((a <= b) && (!stack.isEmpty())) {
          result.push_back(stack.get());
          result.push_back(space);
          stack.pop();
        }
        stack.push(inf[i]);
      }
    }
  }
  while (!stack.isEmpty()) {
    result.push_back(stack.get());
    result.push_back(space);
    stack.pop();
  }
  for (int i = 0; i < result.size(); i++) {
    if (result[result.size() - 1] == ' ') result.erase(result.size() - 1);
  }
  return result;
}
int calculating(char operation, int x, int y) {
  switch (operation) {
    case '+':
      return x + y;
      break;
    case '-':
      return y - x;
      break;
    case '*':
      return x * y;
      break;
    case '/':
      return y / x;
      break;
  }
  return 0;
}
int eval(std::string pref) {
  TStack<int, 100> stack2;
  int intvalue, x, y = 0;
  for (int i = 0; i < pref.size(); i++) {
    if (pref[i] >= '0') {
      stack2.push(pref[i] - '0');
    } else if (priority(pref[i]) <= 3) {
      x = stack2.get();
      stack2.pop();
      y = stack2.get();
      stack2.pop();
      stack2.push(calculating(pref[i], x, y));
    }
  }
  intvalue = stack2.get();
  return intvalue;
}
