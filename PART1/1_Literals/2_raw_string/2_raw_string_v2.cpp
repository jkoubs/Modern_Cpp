#include <iostream>
#include <string>

int main() {

  // OK: contains one backslash,
  // equivalent to "\\"
  std::cout << "-----------------EXAMPLE 1-----------------\n" << std::endl;
  std::cout << R"(\)" << std::endl;

  // OK: contains four \n pairs,
  // equivalent to "\\n\\n\\n\\n"
  std::cout << "-----------------EXAMPLE 2-----------------\n" << std::endl;
  std::cout << R"(\n\n\n\n)" << std::endl;

  // OK: contains one close-parenthesis, two double-quotes and one
  // open-parenthesis, equivalent to ")\"\"("
  std::cout << "-----------------EXAMPLE 3-----------------\n" << std::endl;
  std::cout << R"-()""()-" << std::endl;

  // OK: equivalent to "\n)\\\na\"\"\n"
  std::cout << "-----------------EXAMPLE 4-----------------\n" << std::endl;
  std::cout << R"a(
)\
a""
)a" << std::endl;

  // OK: equivalent to "x = \"\"\\y\"\""
  std::cout << "-----------------EXAMPLE 5-----------------\n" << std::endl;
  std::cout << R"(x = ""\y"")" << std::endl;

  // R"<<(-_-)>>"; // Error: begin and end delimiters do not match
  // R"-()-"-()-"; // Error: )-" appears in the middle and terminates the
  // literal
}