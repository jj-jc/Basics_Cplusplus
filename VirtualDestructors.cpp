#include <iostream>

class Base {
 public:
  Base() { std::cout << "Base Constructor\n"; }
  ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base {
 public:
  Derived() {
    m_Array = new int[5];
    std::cout << "Derived Constructor\n";
  }
  ~Derived() {
    delete[] m_Array;
    std::cout << "Derived Destructor\n";
  }

 private:
  int *m_Array;
};

class CorrectBase {
 public:
  CorrectBase() { std::cout << "CorrectBase Constructor\n"; }
  virtual ~CorrectBase() { std::cout << "CorrectBase Destructor\n"; }
};

class CorrectDerived : public CorrectBase {
 public:
  CorrectDerived() {
    m_Array = new int[5];
    std::cout << "CorrectDerived Constructor\n";
  }
  ~CorrectDerived() {
    delete[] m_Array;
    std::cout << "CorrectDerived Destructor\n";
  }

 private:
  int *m_Array;
};

int main() {
  Base *base = new Base();
  delete base;

  std::cout << "--------------------\n";

  Derived *derived = new Derived();
  delete derived;

  std::cout << "--------------------\n";

  Base *poly = new Derived();  // polimorphic, calls for the Base and Derived
                               // constructors
  delete poly;  // JUST CALL FOR THE BASE DESTRUCTOR, it is a memory leaking
                // because whe do not
  // delete the m_Array vector

  std::cout << "--------------------\n";

  CorrectBase *correctPoly =
      new CorrectDerived();  // polimorphic, calls for the Base and Derived
                             // constructors
  delete correctPoly;        // now, as the destructor is virtual, it is calling
                             // CorrectBase and CorrectDerived destructors
}