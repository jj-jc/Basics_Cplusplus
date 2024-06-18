#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

struct Entity {
  int x, y;
};

int main() {
  int a = 50;
  double value = a;                // implicit conversion from int to double
  double doubleValue = (double)a;  // explicit conversion from int to double
  std::cout << value << std::endl;
  std::cout << doubleValue << std::endl;

  double valueType = *(
      double *)&a;  // type punning the integer to a double. This take the
                    // information literally from the int memory allocation and
  // paste it into the double variable allocation.
  std::cout << valueType << std::endl;

  Entity e = {5, 8};
  int *position = (int *)&e;
  std::cout << position[0] << ", " << position[1] << std::endl;

  int y = *(int *)((char *)&e + 4);
  std::cout << y << std::endl;

  int y2 = *(int *)((int *)&e + 1);
  std::cout << y2 << std::endl;
}