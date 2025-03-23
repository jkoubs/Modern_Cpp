#include <iostream>

int main() {

  // Once you created a ref, you can't change it to refer to something else
  int i, j;
  int &ri = i; // binds ri to i
  ri = j;      // assigns j to i through ri

  std::cout << "&i: " << &i << std::endl;
  std::cout << "&j: " << &j << std::endl;

  // Since you cant change what a ref refers to, you must give it a value at the
  // time you define it

  //   int &ra; // error: initializer required
}