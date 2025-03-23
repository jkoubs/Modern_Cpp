#include <iostream>
#include <vector>

int func(int) { return 2011; }

int main() {

  auto i = 5;
  auto &intRef = i;           // int&
  auto *intPoint = &i;        // int*
  const auto constInt = i;    // const int
  static auto staticInt = 10; // static int

  std::vector<int> myVec;
  auto vec = myVec;   // std::vector<int>
  auto &vecRef = vec; // std::vector<int>&

  int myData[10];
  /*n C++, when an array is used in an expression (except in a few cases, like
   * sizeof or &array), it decays into a pointer to its first element.*/
  auto v1 = myData;  // int* DECAY - v1 is a pointer to the first element (int*)
  auto &v2 = myData; // int (&)[10] - reference to the entire array

  auto myFunc = func; // (int)(*)(int)
  /*myFunc is inferred as a function pointer (int (*)(int)).*/
  auto &myFuncRef = func; // (int)(&)(int)
  /*myFuncRef is inferred as a reference to a function (int (&)(int)).
   */

  // define a function pointer
  int (*myAdd1)(int, int) = [](int a, int b) { return a + b; };

  // use type inference of the C++11 compiler
  auto myAdd2 = [](int a, int b) { return a + b; };

  std::cout << "\n";

  // use the function pointer
  std::cout << "myAdd1(1, 2) = " << myAdd1(1, 2) << '\n';

  // use the auto variable
  std::cout << "myAdd2(1, 2) = " << myAdd2(1, 2) << '\n';

  std::cout << "\n";
}
