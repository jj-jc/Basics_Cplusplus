#include <iostream>

class Entity
{
private:
    const char* m_Name = "Yoyosplay";
    mutable int m_DebugCount = 0;
public:
    const char* getName() const
    {
        m_DebugCount++;
        return m_Name;
    }
};

int main()
{
    const Entity e;
    e.getName();

    int x = 9;
    // this is a definition of a lamda in C++
    auto f = [=]() mutable
    {
        x++; // this is only possible if you define the lambda with mutable keyword
        std::cout << "Hello " << x << std::endl;
    };

    f();
    
    std::cin.get();

}