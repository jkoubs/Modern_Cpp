#include <iostream>
#include <string>
#include <utility>

int main() {

  std::string str1{"ABCDEF"};
  std::string str2;

  std::cout << "\n";

  // initial value
  std::cout << "------------- initial value -------------" << std::endl;
  std::cout << "str1 = " << str1 << '\n';
  std::cout << "str2 = " << str2 << '\n';

  // copy semantics
  std::cout << "------------- copy semantics -------------" << std::endl;
  str2 = str1;
  std::cout << "str2 = str1;\n";
  std::cout << "str1 = " << str1 << '\n';
  std::cout << "str2 = " << str2 << '\n';

  std::cout << "\n";

  std::string str3;

  // initial value
  std::cout << "------------- initial value -------------" << std::endl;
  std::cout << "str1 = " << str1 << '\n';
  std::cout << "str3 = " << str3 << '\n';

  // move semantics
  std::cout << "------------- move semantics -------------" << std::endl;
  str3 = std::move(str1);
  std::cout << "str3 = std::move(str1);\n";
  std::cout << "str1 = " << str1 << '\n';
  std::cout << "str3 = " << str3 << '\n';

  std::cout << "\n";
}
