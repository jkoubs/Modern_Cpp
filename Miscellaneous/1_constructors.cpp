#include <iostream>
#include <string>

class MyClass {
private:
  int *data;        // single int pointer
  int *arr;         // dynamic array
  int size;         // size of the dynamic array
  std::string name; // non-pointer member
  int id;

public:
  // Constructor
  MyClass(int value, std::string n, int i, int s) : name(n), id(i), size(s) {
    data = new int(value);

    arr = new int[size];
    for (int j = 0; j < size; ++j) {
      arr[j] = j * 10; // just filling with sample values
    }
  }

  // Copy Constructor invoked when a new object is created based an existing
  // object

  MyClass(const MyClass &other)
      : name(other.name), id(other.id), size(other.size) {
    data = new int(*other.data); // deep copy for single int

    arr = new int[size]; // deep copy for array
    for (int j = 0; j < size; ++j) {
      arr[j] = other.arr[j];
    }

    std::cout << "Copy constructor called!" << std::endl;
  }

  // Destructor
  ~MyClass() {
    delete data;
    delete[] arr;
  }

  // Print function to test
  void print() const {
    std::cout << "Data: " << *data << ", Name: " << name << ", ID: " << id
              << ", Array: ";
    for (int j = 0; j < size; ++j) {
      std::cout << arr[j] << " ";
    }
    std::cout << std::endl;
  }
};

int main() {
  MyClass original(5, "Jason", 101, 4);
  original.print();

  MyClass copy = original; // triggers copy constructor
  MyClass copy2(original); // same
  copy.print();
  copy2.print();

  return 0;
}

/*

* Copy Constructor invoked when creating new object based on existing object

* Copy Assignment Operator Constructor invoked when reassigning values of
existing object with another existing object


Copy and Copy Assignment Operator Constructors are needed when working with
pointers, otherwise not needed.


Let's see a an example with pointers of 3_constructors_with_pointers.cpp

*/