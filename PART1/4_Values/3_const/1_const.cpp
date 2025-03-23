/*
Rule: A const object can invoke only const member functions
*/

#include <iostream>

struct MyClass {
  void show() const { // const member function
    std::cout << "This is a const method.\n";
  }

  void modify() { //  non-const member function
    std::cout << "This is a modifying method.\n";
  }
};

int main() {
  const MyClass obj; // const object

  obj.show();   // OK
  obj.modify(); //  Error: cannot call non-const function on a const object
}
