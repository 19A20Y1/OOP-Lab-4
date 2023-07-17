/*Write a program that has a class with a dynamically allocated character 
array as its data member. One object should contain "Engineers are" and 
another should contain " Creatures of logic". Member function join() should 
concatenate two strings by passing two objects as arguments. Display the 
concatenated string through a member function. Use constructors to allocate 
and initialize the data member. Also, write a destructor to free the 
allocated memory for the character array. Make your own function for the 
concatenation of two strings.*/
#include <iostream>
#include <cstring>

using namespace std;

class StringConcatenator {
private:
    char* stringData;

public:
    // Constructor
    StringConcatenator(const char* initialString = "") {
        stringData = new char[strlen(initialString) + 1];
        strcpy(stringData, initialString);
    }

    // Destructor
    ~StringConcatenator() {
        delete[] stringData;
    }

    // Member function to concatenate two strings
    void join(const StringConcatenator& str1, const StringConcatenator& str2) {
        delete[] stringData;
        stringData = new char[strlen(str1.stringData) + strlen(str2.stringData) + 1];
        strcpy(stringData, str1.stringData);
        strcat(stringData, str2.stringData);
    }

    // Member function to display the concatenated string
    void display() const {
        cout << "Concatenated string: " << stringData << endl;
    }
};

int main() {
    StringConcatenator obj1("Engineers are");
    StringConcatenator obj2(" Creatures of logic");

    StringConcatenator result;
    result.join(obj1, obj2);
    result.display();

    return 0;
}