#include <iostream>
#include <string>

using String = std::string;


class Entity
{
private:
    String m_Name;
public:
    Entity() : m_Name("Unkown"){}
    Entity(const String& Name) : m_Name(Name){}

    const String& getName() const {return m_Name;}
};


void function()
{
    Entity entity = Entity("Cherno"); // this memory is deleted
}

int main()
{
    // Fastes way to create objects
    Entity entity;
    std::cout << entity.getName() << std::endl;

    Entity* e;
    {
        // Fastes way to create objects
        Entity entity;
        e = &entity;
        std::cout << entity.getName() << std::endl;
    }

    {   
        Entity* entity = new Entity("Juanjo"); // allocate memory into the heap memory to be accesible in other scopes
        // there are some problems to allocate memory in the heap and is:
            // performance
        e = entity;
        std::cout << entity->getName() << std::endl;
        
    }
    

    int a = 2;
    int* b = new int; // 4 bytes
    int* b2 = new int[50]; // 200 bytes

    Entity* e2 = new Entity[50]; // looks at the free memory table and reserves the memory needed in the heap. IT returns a pointer to that especifica memory
    // the diference between an array in heap and in stack is that in heap all the items are stored on e behind the other.
    // the stack will manage the memory, so it can not be done that way.


    // new is an operator
    Entity* e3 = new Entity();
    Entity* e4 = (Entity*)malloc(sizeof(Entity));
    //both lines of code do the same, but with the malloc reservation you are not calling the constructor 
    //for the object, just the memory needed (so is easier use new).

    // new permits you choose especifically the direction for the memory you wanna use to allocate information
    Entity * e5 = new(b) Entity(); // this allocates memory the size of entity in the direction b is pointing at. 

    delete b;
    delete[] b2;

    delete[] e2;
    delete e3;
    free(e4); // for malloc. Calls the destructor as well

    std::cin.get();
    delete e;
}