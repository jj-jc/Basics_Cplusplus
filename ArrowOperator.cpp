#include <iostream>
#include <string>

class Entity
{
public:
    int x;

public:
    void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
    Entity *m_Object;

public:
    ScopedPtr(Entity *entity)
        : m_Object(entity)
    {
    }

    ~ScopedPtr()
    {
        delete m_Object;
    }

    Entity *operator->()
    {
        return m_Object;
    }
};

struct Vector3
{
    float x, y, z;
};

int main()
{
    ScopedPtr entity = new Entity();
    entity->Print();

    ((Vector3 *)nullptr)->x;  // returns the x position of the pointer from 0.
    &((Vector3 *)nullptr)->x; // returns the direction of x position of the pointer from 0.

    float *offset = (float *)&((Vector3 *)nullptr)->y; // returns the offset in memory of the y position in the structure

    std::cout << offset << std::endl;
}