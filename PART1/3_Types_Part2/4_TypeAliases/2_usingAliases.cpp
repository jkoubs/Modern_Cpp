/*
using is similar to typedef but with a different syntax

Lets rewrite the equivalent code as we have seen for typedef
*/

#include <iostream>
#include <vector>

using pairlist_t = std::vector<std::pair<std::string, int>>;
using text_t = std::string;

int main() {

  pairlist_t pairlist;

  text_t my_name = "Jason";

  std::cout << "My name is: " << my_name << std::endl;
  return 0;
}