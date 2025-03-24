#include <iostream>

int main() {
  using T = int;

  T value = 42;

  T *p = &value;           // plain pointer
  T const *pc = &value;    // pointer to const
  T volatile *pv = &value; // pointer to volatile

  // OK: assigning T* to T const*
  pc = p; // OK: adding const is safe

  // ERROR: assigning T const* to T*
  // p = pc;     // ERROR: loses const (unsafe)

  // OK: assigning T* to T volatile*
  pv = p; // OK: adding volatile is safe

  // ERROR: assigning T volatile* to T*
  // p = pv;     // ERROR: loses volatile (unsafe)

  // ERROR: assigning T const* to T volatile*
  // pv = pc;    // ERROR: adds volatile, but loses const

  return 0;
}
