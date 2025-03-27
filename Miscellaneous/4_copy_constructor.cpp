#include <iostream>
#include <string>

class MyClass {
private:
  std::string name;

public:
  // Constructor
  MyClass(const std::string &n) : name(n) {
    std::cout << "Constructor called for: " << name << std::endl;
  }

  // Copy Constructor
  MyClass(const MyClass &other) {
    name = other.name;
    std::cout << "Copy constructor called for: " << name << std::endl;
  }

  // Function to print name
  void print() const { std::cout << "Object name: " << name << std::endl; }
};

// 2) Passing an object by value
void printObject(MyClass obj) {
  std::cout << "Inside printObject function..." << std::endl;
  obj.print();
}

// 3) Returning an object by value
MyClass createObject() {
  MyClass temp("TempObject");
  return MyClass(temp); // Forces copy constructor
  //   return temp;  // does not work
}

int main() {
  // 1) Creating a new object from an existing object
  MyClass original("Original");
  MyClass copy1 = original; // copy constructor is called

  std::cout << "\n--- Passing by value ---\n";
  printObject(original); // copy constructor is called

  std::cout << "\n--- Returning from function ---\n";
  MyClass returned = createObject(); // copy constructor *may* be called (copy
                                     // elision may occur)

  return 0;
}

/*

Use of copy constructors:

1) Whenever you are creating a new object based on an already existing object
2) When an object is passed as a param to a fct (by value)
3) When return an object from a fct (by value)

*/