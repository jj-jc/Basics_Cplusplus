
#include <iostream>
#include <string>
#include <vector>

class Singleton
{
private:
    static Singleton *s_Instance;

public:
    static Singleton &get() { return *s_Instance; }
};

void function()
{
    static int i = 0; // the first time, it creates the variable and initialize it to 0.
    i++;
    std::cout << i << std::endl;
}

Singleton *Singleton::s_Instance = nullptr;

int main()
{
    function();
    function();
    function();
}