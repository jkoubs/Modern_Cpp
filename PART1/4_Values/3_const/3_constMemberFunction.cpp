/*

Member functions can be qualified with const to indicate they do not modify the
object's state.

const Member Function (Read-only)

*/

#include <iostream>

class MyClass {
private:
  int value;

public:
  MyClass(int v) : value(v) {}

  void display() const { // const member function
    std::cout << "Value is: " << value << "\n";
    // value = 10;      This would cause a compile-time error
  }
};

int main() {
  const MyClass obj(42); // const object
  obj.display();         // Allowed: display() is a const function
}
