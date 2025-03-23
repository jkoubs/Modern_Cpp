#include <iostream>

int main() {

  int i = 13;
  unsigned long ul = 42;

  int *pi = &i;             // pointer to int
  unsigned long *pul = &ul; // pointer to unsigned long

  *pi = 14;  // store 14 into i
  *pul += 2; // add 2 to ul

  std::cout << "*pi = " << *pi << std::endl;
  std::cout << "*pul = " << *pul << std::endl;

  std::cout << "---------------------" << std::endl;

  std::cout << "i = " << i << std::endl;
  std::cout << "ul = " << ul << std::endl;

  return 0;
}