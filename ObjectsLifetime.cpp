#include <iostream>
#include <string>

class Entity
{
public: 
    Entity() { std::cout << "Created Entity!" << std::endl;}
    ~Entity() { std::cout << "Destroyed Entity!" << std::endl;}
};

int* CreateArray()
{
    int array[50];
    return array;
}

// scoped pointer class (Like unique_ptr in the std library)
class ScopedPtr
{
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr)
        :m_Ptr(ptr)
    {

    }

    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};


int main()
{
    {
        Entity(); // This is destroyed because is inside the stack memory
    }

    {
        Entity* e = new Entity(); // This is not destroyed because is in the heap memory
    }

    {
        ScopedPtr e = new Entity(); // this is an object that stores in stack the pointer. This forces to delete the pointer once the ScopedPtr destructor is called
    }

    std::cout << "main Scope" << std::endl;

    std::cin.get();
}