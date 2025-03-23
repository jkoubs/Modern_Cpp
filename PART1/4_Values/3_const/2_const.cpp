/*
Rule: A non-const object can invoke both const and non-const member functions
*/

#include <iostream>

struct MyClass {
  void show() const { std::cout << "This is a const method.\n"; }

  void modify() { std::cout << "This is a modifying method.\n"; }
};

int main() {
  MyClass obj; // non-const object

  obj.show();   // OK
  obj.modify(); // OK
}
