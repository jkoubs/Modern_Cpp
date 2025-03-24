/*
Typedef gives a new identifier to an existing data type

Its like giving a surname an easier way to read code and reduce typos

Can be useful when ou are dealing with complex data types
*/

#include <iostream>
#include <vector>

typedef std::vector<std::pair<std::string, int>> pairlist_t;
typedef std::string text_t;

int main() {

  pairlist_t pairlist;

  text_t my_name = "Jason";

  std::cout << "My name is: " << my_name << std::endl;
  return 0;
}
