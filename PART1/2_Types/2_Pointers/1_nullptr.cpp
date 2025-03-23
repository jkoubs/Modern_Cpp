#include <iostream>
#include <typeinfo>

int main() {

  int *a = nullptr;
  // null pointer constant behaves like a boolean value initialized with false
  if (!a) {
    std::cout << "will be called" << std::endl;
    std::cout << "Type of a: " << typeid(a).name() << std::endl;
  }
}
