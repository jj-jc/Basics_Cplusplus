#include <iostream>

class Entity
{
public:
    int x, y;

    Entity(int x, int y)
    {
        Entity *const e = this; // this is a pointer that points to the current instancie
        // as
        this->x = x;
        this->y = y;
    }

    int getX() const
    {
        const Entity *e = this;
    }
};

int main()
{
    std::cin.get();
}