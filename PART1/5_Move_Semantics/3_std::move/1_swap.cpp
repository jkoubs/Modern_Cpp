#include <iostream>
#include <utility>
#include <vector>

template <typename T> void swap(T &a, T &b) {
  T tmp(std::move(a));
  a = std::move(b);
  b = std::move(tmp);
}

struct MyData {
  std::vector<int> myData;

  MyData() : myData({1, 2, 3, 4, 5}) {}

  // move constructor
  MyData(MyData &&m) : myData(std::move(m.myData)) {
    std::cout << "move constructor" << '\n';
  }

  // copy semantic
  MyData(const MyData &m) : myData(m.myData) {
    std::cout << "copy constructor" << '\n';
  }

  MyData &operator=(const MyData &m) {
    myData = m.myData;
    std::cout << "copy assignment operator" << '\n';
    return *this;
  }
};

int main() {

  std::cout << '\n';

  MyData a, b;
  swap(a, b);

  std::cout << '\n';
};

/*
Copy Semantics is the fallback of Move Semantics

Moving is an optimized copying

*/