#include <iostream>
#include <string> // overload of << for std::string data types

void printString(const std::string& string) // pass a reference instead of a copy of the string
{
    std::cout << string << std::endl;
}

int main()
{
    // Strings in C++
    const char* name = "Cherno"; // String pointer because of the ""
    char name3[] = {'C', 'h', 'e', 'r', 'n','o', '\0'};
    char name2[6] = {'C', 'h', 'e', 'r', 'n','o'};

    std::cout << name << std::endl; // cout will print everything till the \0 character
    std::cout << name2 << std::endl;
    std::cout << name3 << std::endl;

    // Strings in std 
    std::string name4 = "Cherno" + std::string(" hello");
    bool contains = name4.find("no") != std::string::npos;
    std::cout << name4 << std::endl;


    std::cin.get();

}