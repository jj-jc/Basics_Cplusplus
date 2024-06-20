#include <boost/type_index.hpp>
#include <iostream>
#include <vector>

template <typename T>
void f(T param) {
  std::cout << "DeducingTypes!!" << '\n';
}

template <typename T>
class TD;

template <typename T>
void function(const T& param) {
  std::cout << "T = " << typeid(T).name() << '\n';
  std::cout << "param = " << typeid(param).name() << '\n';
}

std::vector<int> createVec() {
  std::vector<int> a = {1, 2, 3, 5, 7};
  return a;
}

template <typename T>
void TypeIndex(const T& param) {
  using boost::typeindex::type_id_with_cvr;
  using std::cout;

  // Showing T type
  cout << "T = " << type_id_with_cvr<T>().pretty_name() << '\n';

  // Showing param type
  cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name()
       << '\n';
}

int main() {
  const int theAnswer = 42;
  const int& lValue = 24;
  auto x = theAnswer;
  auto y = &theAnswer;
  const auto b = &theAnswer;
  auto& z = theAnswer;
  auto& a = lValue;

  f(&theAnswer);

  // TD<decltype(a)> xType;

  std::cout << typeid(x).name() << "\n";
  std::cout << typeid(y).name() << "\n";

  const auto vw = createVec();

  function(&vw[0]);

  TypeIndex(&vw[0]);

  return true;
}