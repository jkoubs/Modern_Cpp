/*
DEFINITION:

A dangling pointer in C++ is a pointer that refers to a memory location that has
been deallocated or is no longer valid. Accessing such a pointer can lead to
undefined behavior, including crashes, corrupted data, or security
vulnerabilities.
*/

// EXAMPLE 1: Deleting a pointer but still using it

int *ptr = new int(10);
delete ptr; // Memory is freed
*ptr = 20;  // Undefined behavior! ptr is now dangling

// EXAMPLE 2: Returning a pointer to a local variable
// x is supposed to die at the end of the fct scope since its a local variable,
// thus cannot return it since will not exist anymore
// getPointer() return &x, but x no longer exists
int *getPointer() {
  int x = 5;
  return &x; // x is destroyed when function exits
}

int *ptr = getPointer(); // ptr now points to invalid memory
