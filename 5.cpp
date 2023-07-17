/*Write a program that illustrates the following relationship and comment 
on them. 
i) const_object.non_const_mem_function
ii) const_object.const_mem_function
iii) non_const_object.non_const_mem_function
iv) non_const_object.const_mem_function*/
#include <iostream>

using namespace std;

class MyClass {
private:
  int value;

public:
  MyClass(int v) : value(v) {}

  void nonConstMemberFunction() {
    cout << "Non-const member function called. Value: " << value << endl;
  }

  void constMemberFunction() const {
    cout << "Const member function called. Value: " << value << endl;
  }
};

int main() {
  const MyClass constObj(10);
  MyClass nonConstObj(20);

  // i) const_object.non_const_mem_function
  // This is not allowed because a const object cannot call non-const member functions.
  // constObj.nonConstMemberFunction(); // Error: Non-const member function cannot be called on const object

  // ii) const_object.const_mem_function
  // This is allowed because a const object can call const member functions.
  constObj.constMemberFunction(); // Const member function called. Value: 10

  // iii) non_const_object.non_const_mem_function
  // This is allowed because a non-const object can call both non-const and const member functions.
  nonConstObj.nonConstMemberFunction(); // Non-const member function called. Value: 20

  // iv) non_const_object.const_mem_function
  // This is allowed because a non-const object can call const member functions.
  nonConstObj.constMemberFunction(); // Const member function called. Value: 20

  return 0;
}
