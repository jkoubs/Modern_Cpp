/*
Literals are fixed values that are directly written into the code.
They represent constant values of different types and do not change during
program execution.
*/

#include <iostream>
// User-defined literal for kilometers to meters conversion
constexpr long double operator"" _km(long double x) {
  return x * 1000; // Convert km to meters
}

int main() {
  // Integer literals
  int decimal = 42;
  int octal = 052;       // Starts with 0
  int hex = 0x2A;        // Starts with 0x
  int binary = 0b101010; // Starts with 0b

  // Floating-point literals
  double pi = 3.14159;
  float e = 2.71f;         // 'f' suffix for float
  double largeNum = 1.2e6; // Scientific notation

  // Character literals
  char letter = 'A';
  char newline = '\n'; // Escape sequence for new line
  char tab = '\t';     // Escape sequence for tab

  // String literals
  const char *greeting = "Hello, World!";
  const char *rawStr = R"(This is a raw string
spanning multiple lines
with "quotes" and \ backslashes)";

  // Boolean literals
  bool isReady = true;
  bool isFinished = false;

  // Pointer literals
  int *ptr = nullptr;

  // User-defined literal
  long double distance = 5.0_km;

  // Output demonstration
  std::cout << "Integer Literals:\n";
  std::cout << "Decimal: " << decimal << "\n";
  std::cout << "Octal: " << octal << " (Displayed as decimal)\n";
  std::cout << "Hex: " << hex << " (Displayed as decimal)\n";
  std::cout << "Binary: " << binary << " (Displayed as decimal)\n\n";

  std::cout << "Floating-Point Literals:\n";
  std::cout << "Pi: " << pi << "\n";
  std::cout << "Euler's number: " << e << "\n";
  std::cout << "Large Number (scientific notation): " << largeNum << "\n\n";

  std::cout << "Character Literals:\n";
  std::cout << "Letter: " << letter << "\n";
  std::cout << "Newline and Tab are not visible but functional.\n\n";

  std::cout << "String Literals:\n";
  std::cout << "Greeting: " << greeting << "\n";
  std::cout << "Raw String: \n" << rawStr << "\n\n";

  std::cout << "Boolean Literals:\n";
  std::cout << "isReady: " << isReady << "\n";
  std::cout << "isFinished: " << isFinished << "\n\n";

  std::cout << "Pointer Literal:\n";
  std::cout << "Pointer value: " << ptr << "\n\n";

  std::cout << "User-Defined Literal:\n";
  std::cout << "Distance in meters (from 5.0 km): " << distance << "m\n";

  return 0;
}
