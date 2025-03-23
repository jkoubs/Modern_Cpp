#include <iostream>
#include <typeinfo>

class Base {};
class Derived : public Base {};

int main() {
  int a = 10;
  double b = static_cast<double>(a); // int → double

  Derived d;
  Base *basePtr = static_cast<Base *>(&d); // Upcasting: Derived → Base

  std::cout << "Converted int to double: " << b << std::endl;
  std::cout << "Type of b: " << typeid(b).name() << std::endl;
  std::cout << "Type of d: " << typeid(d).name() << std::endl;
  return 0;
}

/*

Used for:
* Implicit and explicit conversions between related types.
* Converting int to double, char to int, etc.
* Upcasting in inheritance (Base class ← Derived class).


Limitations:
* Cannot remove const or volatile qualifiers.
* Cannot cast between completely unrelated types (e.g., int* to double*).
*/