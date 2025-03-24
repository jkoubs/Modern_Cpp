#include <iostream>

// Function that takes a reference to a non-const int
void wi(int &r) { std::cout << "Function wi called with: " << r << std::endl; }

// Function that takes a reference to a const int
void wci(const int &rc) {
  std::cout << "Function wci called with: " << rc << std::endl;
}

int main() {
  int i = 37;        // Regular int
  const int ci = 42; // Const int

  wi(i); // OK: ref to int bound to int
  // wi(ci);  // ERROR: can't bind non-const ref to const int

  wci(ci); // OK: ref to const int bound to const int
  wci(i);  // OK: ref to const int can also bind to non-const int (safe)

  return 0;
}
