#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  std::vector<int> values = {1, 2, 3, 4, 5};

  std::cout << "Simple iteration" << std::endl;
  for (int i = 0; i < values.size(); i++) {
    std::cout << values[i] << std::endl;
  }

  std::cout << "Iteration over the value" << std::endl;
  for (int value : values) {
    std::cout << value << std::endl;
  }

  std::cout << "Vector iterators" << std::endl;
  for (std::vector<int>::iterator it = values.begin(); it != values.end();
       it++) {
    std::cout << *it << std::endl;
  }

  using ScoreMap = std::unordered_map<std::string, int>;
  using ScoreMapConstIterator = ScoreMap::const_iterator;
  ScoreMap map;
  map["Cherno"] = 5;
  map["C++"] = 2;
  std::cout << "Unordered_map iterator " << std::endl;
  for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++) {
    auto &key = it->first;
    auto &value = it->second;
    std::cout << key << " = " << value << std::endl;
  }

  std::cout << "Unordered_map range loop " << std::endl;
  for (auto kv : map) {
    auto &key = kv.first;
    auto &value = kv.second;
    std::cout << key << " = " << value << std::endl;
  }

  std::cout << "Unordered_map range loop in C++17"
            << std::endl;  // this use structure bindings
  for (auto [key, value] : map) {
    std::cout << key << " = " << value << std::endl;
  }
}