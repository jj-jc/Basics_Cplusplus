#include <iostream>

class Singleton {
 public:
  Singleton(const Singleton &) = delete;  // avoids the copy constructor

  static Singleton &get() { return s_Instance; }

 private:
  Singleton(){};
  static Singleton s_Instance;
};

Singleton Singleton::s_Instance;

class Random {
 public:
  Random(const Random &) = delete;  // avoids the copy constructor

  static Random &get() { return s_Instance; }

  static float generateFloat() { return get().IgenerateFloat(); }

 private:
  Random(){};
  float IgenerateFloat() { return m_randomFloat; }
  static Random s_Instance;
  float m_randomFloat = 0.05f;
};

Random Random::s_Instance;

int main() {
  auto &singletonInstance = Singleton::get();

  float randomNumber = Random::get().generateFloat();

  std::cout << randomNumber << std::endl;
}