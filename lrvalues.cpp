#include <iostream>
#include <typeinfo>

void printName(std::string& name)
{
    std::cout << "[lvalue] " << name << std::endl;
}

void printConstName(const std::string& name)
{
    std::cout << "[either lvalue or rvalue] " <<name << std::endl;
}

void printRValueName(std::string&& name)
{
    std::cout << "[rvalue] " << name << std::endl; // takes the reference to that temporary rvalue
}


int main()
{
    // i is lvalue and 10 is ravlue
    int i = 10;
    int a = i; // a and i are lvalues
    std::string firstName = "Yan"; // firstName is a lvalue and "Yan" is a rvalue
    std::string lastName = "Chernikov"; // lastName is a lvalue and "Chernikov" is a rvalue

    std::string fullName = firstName + lastName; // fullname is a lvalue. firstName + lastName is an operation of const strings so are rvalues ( it returns a const char* directly)

    printName(fullName);
    // printName(firstName + lastName); // this returns an error. A lvalue reference cannot take from a rvalue
    printConstName(fullName);
    printConstName(firstName + lastName); // this accepts the const char* 

    // printRValueName(fullName); // this return an error. An rvalue reference cannot be bound to an lvalue C/C++(1768)
    printRValueName(firstName + lastName);

    // std::cout << typeid(firstName + lastName).name() << std::endl;
    // std::cout << typeid(fullName).name() << std::endl;
}