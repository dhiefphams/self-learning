#include <iostream>
#include <cstring>
#include <string>

/**
 * typedef
 */
typedef unsigned long DWORD;

// often in C
typedef struct qq {
  int x, y;
} KPoint;

// in modern C++
struct KPoint2 {
  int x, y;
};



/**
 * Function pointers
 *
 * C: function pointers
 * C++: Polymorphism
 * C++11: lambdas
 * 
 * Easy to set and use
 * We can use typedef
 */
int doubler(int i) {
  return i * 2;
}

int tripler(int i) {
  return i * 3;
}

// define a function pointer, take int param and return an int
typedef int (*CHANGER)(int i);

int Change(int i) {
  CHANGER fn;
  if (i > 5) {
    fn = tripler;
  } else {
    fn = doubler;
  }
  return fn(i);
}

class Utility {
  private:
    int x;
  public:
    Utility(int x): x{x} {}

    int doublex() {
      return x * 2;
    }

    int triplex() {
      return x * 3;
    }
};

// Member function pointer
typedef int (Utility::* Fn)();

int ChangeMethod(int x) {
  Utility u(x);
  Fn action;
  if (x > 3) {
    action = &Utility::triplex; // get reference to the class method
  } else {
    action = &Utility::doublex;
  }
  return (u.*action)(); // call the function given context
}

// Void ptr
// Use to indicate a pointer to anything
// char*, int* can cast to void* and forth
// danger

void UseSomething(void* sth) {
  // cast to int
  // Cls* s = dynamic_cast<Cls*>(sth);
  int* s = (int*) sth; // no protection
  std::cout << *s << std::endl;
}

// C style arrays
// use std::vector instead
void CArrays() {
  int ints[3] = {1, 2, 3};
  // actually, ints point to the first address item in the array
  std::cout << "first " << *ints << std::endl;
  std::cout << "Second " << *(ints + 1) << std::endl;
  std::cout << "Third " << *(ints + 2) << std::endl;
  // the 4th elem can prone some mystery error
  // *(ints + 3) = 2;

  // float floats[] = {1.0, 1.2, 3.0};
  // or
  // int* arr = new int[4];
  // access value
  std::cout << "Index 0 " << ints[0] << std::endl;
  // free array
  // delete[] ints;
}

// C strings
// Null characters : `\0`
// `'0'` # `"9"`
// unsave & unintuitive

void CString() {
  char* s1 = "Hello";
  int i = strlen(s1);
  std::cout << "The length of `Hello` is " <<  i << std::endl;
  char* s2 = new char[i + strlen(" Kate")];
  strcpy(s2, s1);
  std::cout << s2 << std::endl;
  strcat(s2, " Kate");
  std::cout << s2 << std::endl;
  char hello[] = {' ', 'w', 'o', 'r', 'l', 'd'};
  std::cout << "Lenght of h is " << strlen(hello) << std::endl;
  delete[] s2;
}

int main() {
  std::cout << "Fn pointer " << Change(10) << std::endl;
  std::cout << "Method pointer " << ChangeMethod(20) << std::endl;
  std::string a = "aaa";
  UseSomething(&a);
  CArrays();
  CString();
}
