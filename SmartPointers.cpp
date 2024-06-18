#include <iostream>
#include <memory>
#include <string>

class Entity {
 public:
  Entity() { std::cout << "Created Entity!" << std::endl; }

  ~Entity() { std::cout << "Destroyed Entity!" << std::endl; }
  void print() { std::cout << "Print!" << std::endl; }
};

int main() {
  std::shared_ptr<Entity>
      e0;  // once all the references scopes ends will delete the memory
           // allocation ( in this example in the final of this program)
  {
    // UNIQUE POINTER
    // std::unique_ptr<Entity> entity(new Entity()); // create an unique pointer
    // explicity std::unique_ptr<Entity> entity = new Entity(); // This way is
    // not possible (copy of a pointer) std::unique_ptr<Entity> entity2 =
    // std::make_unique<Entity>(); // safest way to create a smart pointer
    // entity->print();

    // SHARED POINTER
    std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
    e0 = sharedEntity;

    // WEAK POINTER
  }

  std::cin.get();
}
