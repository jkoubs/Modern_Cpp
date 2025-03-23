#include <iostream>

int main() {

  // Assign a Value via Pointer
  std::cout << "\n************* 1 - Assign a Value via Pointer *************\n"
            << std::endl;

  int size = 10;
  char x[size];
  char *pc = &x[0];

  *pc = 'a'; // x[0] = 'a'
  std::cout << "x[0] = " << x[0] << std::endl;
  std::cout << "*pc = " << *pc << std::endl;
  std::cout << "&pc =" << &pc << std::endl;

  // Point to the next element
  std::cout << "\n************* 2 - Point to the next element *************\n"
            << std::endl;

  ++pc;      // pc now points to x[1], point to next element in the array
  *pc = 'c'; // x[1] = c

  std::cout << "x[0] = " << x[0] << std::endl;
  std::cout << "x[1] = " << x[1] << std::endl;
  std::cout << "*pc = " << *pc << std::endl;
  std::cout << "&pc =" << &pc << std::endl;

  // Pointer to step through elements of an array

  std::cout
      << "\n************* 3 - Pointer to step through elements of an array "
         "*************\n"
      << std::endl;

  int nums[5] = {1, 2, 3, 4, 5};
  for (int *p = nums; p < nums + 5; ++p) {
    std::cout << *p << " ";
  }
  std::cout << std::endl;

  // Pointer Addition
  // Adding an int to a pointer yields another pointer

  std::cout << "\n************* 4 - Pointer Addition *************\n"
            << std::endl;

  int my_nums[5] = {10, 20, 30, 40, 50};
  int *p;
  p = my_nums; // Pointer pointing to the first element of the array
               // (my_nums "decays" to &my_nums[0])
  std::cout << "Initial value at p: " << *p << std::endl;

  p = p + 2; // Move pointer forward by 2 elements

  std::cout << "Value at p after addition: " << *p << std::endl;

  return 0;
}
