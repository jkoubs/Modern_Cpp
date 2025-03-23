#include <iostream>
#include <tuple>
#include <utility> // for std::pair

// 4. User-defined aggregate struct
struct Point {
  int x;
  int y;
};

int main() {
  // 1. Structured Binding with Array
  int arr[3] = {10, 20, 30};
  auto [a1, a2, a3] = arr;
  std::cout << "Array elements: " << a1 << ", " << a2 << ", " << a3 << "\n";

  // 2. Structured Binding with std::pair
  std::pair<std::string, int> person = {"Alice", 30};
  auto [name, age] = person;
  std::cout << "Pair: " << name << " is " << age << " years old\n";

  // 3. Structured Binding with std::tuple
  std::tuple<int, char, double> data = {42, 'x', 3.14};
  auto [id, symbol, pi] = data;
  std::cout << "Tuple: id=" << id << ", symbol=" << symbol << ", pi=" << pi
            << "\n";

  // 4. Structured Binding with user-defined struct
  Point pt{5, 7};
  auto [px, py] = pt;
  std::cout << "Point: x=" << px << ", y=" << py << "\n";

  return 0;
}
