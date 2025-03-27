#include <iostream>

class NonCopyableClass {
public:
  // state the compiler generated default constructor
  NonCopyableClass() = default;

  // disallow copying (copy semantics)
  NonCopyableClass &
  operator=(const NonCopyableClass &) = delete; // Copy Assignment Operator
  NonCopyableClass(const NonCopyableClass &) = delete; // Copy Constructor

  // allow moving (move semantics)
  NonCopyableClass &
  operator=(NonCopyableClass &&) = default;        // Move Assignment Operator
  NonCopyableClass(NonCopyableClass &&) = default; // Move Constructor
};

class TypeOnStack {
public:
  void *operator new(std::size_t) =
      delete; // Disallow Heap Allocation - Class only lives on the stack
};

class TypeOnHeap {
public:
  ~TypeOnHeap() = delete;
};

void onlyDouble(double) {}

template <typename T>
void onlyDouble(T) = delete; // Avoids implicit conversions

int main() {

  NonCopyableClass nonCopyableClass;

  TypeOnStack typeOnStack;

  TypeOnHeap *typeOnHeap = new TypeOnHeap;

  onlyDouble(3.14);

  // force the compiler errors

  /*
    NonCopyableClass nonCopyableClass2(nonCopyableClass);

    TypeOnStack *typeOnHeap2 = new TypeOnStack;

    TypeOnHeap typeOnStack2;

    onlyDouble(2011);
    */
}

/*
default/delete can guide the creation/suppression of special member fcts!

default = creation
delete = suppression
*/