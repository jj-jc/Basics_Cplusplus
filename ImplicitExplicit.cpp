#include <iostream>
#include <string>

class Entity {
 private:
  std::string m_Name;
  int m_Age;

 public:
  Entity(const std::string &name) : m_Name(name), m_Age(-1) {}

  /*explicit*/ Entity(int age)  // Explicit keyword works to disable the
                                // implicit conversion of the compiler
      : m_Name("Unkown"), m_Age(age) {}
};

void printEntity(const Entity &entity) {
  // Printing
}
int main() {
  Entity a("Cherno");
  Entity b(22);
  const std::string name = "Cherno";

  Entity c = name;  // implicity conversion (it has to be const string instead
                    // of const char [] because the compiler is only permitted
                    // to make one conversion implicity)
  Entity d = 22;    // implicity conversion
  Entity e = 22.2f;

  printEntity(22);
  // printEntity("Cherno"); it is not possible
  printEntity(name);

  std::cin.get();
}