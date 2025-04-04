#include <iostream>

constexpr int gcd(int a, int b) {
  while (b != 0) {
    auto t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main() {

  std::cout << '\n';

  // use constexpr at compile time bc 100 and 10 are constants
  constexpr auto res = gcd(100, 10);
  std::cout << "gcd(100, 10) " << res << '\n';

  auto val = 100;
  // use constexpr at run time bc val is not const
  auto res2 = gcd(val, 10);
  std::cout << "gcd(val, 10) " << res2 << '\n';
}
