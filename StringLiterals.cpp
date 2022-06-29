#include <iostream>
#include <string> // overload of << for std::string data types

int main()
{
    // String no Literals 
    // char name[] = "Cherno";
    std::string name = "Cherno";
    name[3] = 'a'; 
    // String Literals 
    // char* name = "Cherno";
    // name[3] = 'a'; 
    // This is not possible to edit en Release mode. This behavior is not defined in the 
    // std of c++ so it depends on the compiler. The reason is because it is treated as a String literal
    // and is stored in only-read memory.

    const wchar_t* name2 = L"Cherno"; // wide string instead of 1 byte
    const char16_t* name3 = u"Cherno"; // 16 bits
    const char32_t* name4 = U"Cherno"; // 32 bits



    std::cout << name << std::endl;


    std::cin.get();

}