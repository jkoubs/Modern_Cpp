#include <iostream>
#include <string>
using namespace std;

// For numeric literals like 123_raw
unsigned long long operator"" _raw(unsigned long long num) {
  cout << "Raw number: " << num << endl;
  return num;
}

// For string literals like "Hello, World!"_raw
void operator"" _raw(const char *str, size_t) {
  cout << "Raw string: " << str << endl;
}

int main() {
  123_raw;             // Numeric literal
  "Hello, World!"_raw; // String literal
  return 0;
}
