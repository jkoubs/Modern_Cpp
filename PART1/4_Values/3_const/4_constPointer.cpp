/*

const T *p             // (1)
T const *p             // (2)
T *const p             // (3)
const T *const p       // (4)
T const *const p       // (5)

----------------------------------------------------------------------------------
   DECLARATION                MEANING                MODIFY *p?       CHANGE p?
---------------------------------------------------------------------------------
     const T *p          Ptr to a cst value             NO              YES
     T const *p
---------------------------------------------------------------------------------
     T *const p             Cst ptr to a                YES             NO
                           variable value
---------------------------------------------------------------------------------
   const T *const p      Cst ptr to a cst value         NO              NO
   T const *const p
----------------------------------------------------------------------------------

*/
#include <iostream>

int main() {

  int x = 10, y = 20;
  std::cout << "x = " << x << ", y = " << y << std::endl;

  // CASE (1) & (2): Pointer to a constant value
  std::cout << " ************* CASE (1) & (2): Pointer to a constant value "
               "************* "
            << std::endl;
  const int *ptr1 = &x;
  // *ptr1 = 15; // Error: Cannot modify value
  ptr1 = &y; // Allowed Pointer can change

  // CASE (3): Constant pointer to a variable value
  int *const ptr2 = &x;
  *ptr2 = 15; // Allowed: Value can be modified
  // ptr2 = &y; // Error: Cannot change pointer

  // CASE (4) & (5): Constant pointer to a constant value
  const int *const ptr3 = &x;
  // *ptr3 = 15; // Error: Cannot modify value
  //   ptr3 = &y; // Error: Cannot change pointer

  std::cout << "x = " << x << ", y = " << y << std::endl;
  return 0;
}