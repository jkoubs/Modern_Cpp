#include <iostream>
#include <typeinfo>

// Unscoped Enums (Also called classical enums)
//  enum Color { red, blue, green };

// Scoped Enums (Also called strongly-typed enums)
enum class Color1 { red, blue, green };

enum struct Color2 : char {
  red = 100,
  blue, // 101
  green // 102
};

void useMe(Color2 color2) {

  switch (color2) {
  case Color2::red:
    std::cout << "Color2::red" << '\n';
    break;
  case Color2::blue:
    std::cout << "Color2::blue" << '\n';
    break;
  case Color2::green:
    std::cout << "Color2::green" << '\n';
    break;
  }
}

int main() {

  std::cout << '\n';
  // To print the int value of the enum, we need to cast it
  std::cout << "static_cast<int>(Color1::red): "
            << static_cast<int>(Color1::red) << '\n';
  std::cout << "static_cast<int>(Color2::red): "
            << static_cast<int>(Color2::red) << '\n';

  std::cout << '\n';

  std::cout << "sizeof(Color1) = " << sizeof(Color1) << '\n';
  std::cout << "sizeof(Color2) = " << sizeof(Color2) << '\n';

  std::cout << '\n';

  std::cout << "-----------------------" << std::endl;

  Color2 color2Red{Color2::red};
  useMe(color2Red);

  std::cout << '\n';
}

/*
1)

classical VS strongly-typed enums

or

Unscoped VS Scoped enums

2) You can explicitly specify the type of enumerators. By default, it’s int.

*/