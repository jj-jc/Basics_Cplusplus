#include <array>
#include <iostream>

void printArray(std::array<int, 5> array) {
  std::cout << "Array = { ";
  for (const auto& item : array) {
    if (array[0] != item) std::cout << ", ";
    std::cout << item;
  }
  std::cout << "}" << std::endl;
}

int main() {
  std::array<int, 5> data{1, 2, 3, 5, 7};

  printArray(data);

  return true;
}