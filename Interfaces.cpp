    
#include <iostream>
#include <string>

class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    virtual std::string GetName() {return "Entity";}
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name) {}

    std::string GetName() override {return m_Name;}
    std::string GetClassName() override {return m_Name;}
};


int main()
{
    Entity* e = new Player("Jojosplay");
    std::cout << e -> GetName() << std::endl;
    
    Player* p = new Player("Cherno");
    std::cout << p -> GetName() << std::endl;

    Entity* entity = p;
    std::cout << entity -> GetName() << std::endl;

    // This is not posible to instanciate because doesn't override the virtual pure method of Printable
    //Entity ent; 

    std::cin.get();
}