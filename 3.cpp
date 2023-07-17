/*Write a class that can store Department ID and Department Name with 
constructors to initialize its members. Write destructor member in the 
same class and display the message "Object n goes out of the scope". Your 
program should be made such that it should show the order of constructor 
and destructor invocation.*/
#include <iostream>
#include <string>

using namespace std;

class Department {
private:
  int departmentId;
  string departmentName;

public:
  // Parameterized constructor
  Department(int id, const string& name) : departmentId(id), departmentName(name) {
    cout << "Constructor called for department " << departmentId << endl;
  }

  // Destructor
  ~Department() {
    cout << "Destructor called for department " << departmentId << endl;
  }
};

int main() {
  // Creating department objects
  Department d1(1, "HR");
  Department d2(2, "Finance");
  
  // Object scope ends here, destructors will be called
  return 0;
}