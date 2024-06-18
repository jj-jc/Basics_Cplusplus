#include <iostream>
class Base {
 public:
  Base(){};
  virtual ~Base(){};
};

class Derived : public Base {
 public:
  Derived(){};
  ~Derived(){};
};

class AnotherClass : public Base {
 public:
  AnotherClass(){};
  ~AnotherClass(){};
};

int main() {
  int a = 5;
  double value = a;
  double value2 = (int)value;
  std::cout << value2 << std::endl;

  double s = static_cast<int>(value) + 5.3;

  Derived *derived = new Derived();

  Base *base = derived;

  AnotherClass *ac = dynamic_cast<AnotherClass *>(
      base);  // this is suppose to be a runtime error.
  if (!ac) {
    std::cout << "It is not correctly casted" << std::endl;
  }

  Derived *dc =
      dynamic_cast<Derived *>(base);  // this is suppose to be a runtime error.
  if (!dc)
    std::cout << "It is not correctly casted" << std::endl;
  else
    std::cout << "It is correctly casted" << std::endl;
}