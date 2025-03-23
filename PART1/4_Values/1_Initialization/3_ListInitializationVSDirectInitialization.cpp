#include <iostream>
#include <vector>

int main() {

  std::vector<int> x{5, 10}; // list initialization
  std::vector<int> y(
      5, 10); // direct initialization (vector of size 5 with value 10)

  std::cout << "List Initialization: \n";
  for (auto i : x) {
    std::cout << i << " ";
  }
  std::cout << "\n\n";

  std::cout << "Direct Initialization: \n";
  for (auto i : y) {
    std::cout << i << " ";
  }
  std::cout << "\n\n";
}
