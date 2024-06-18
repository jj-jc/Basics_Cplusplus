
#include <iostream>
#include <string>
#include <vector>

class Entity {};

struct Vertex {
  float x, y, z;
  Vertex(float x, float y, float z) : x(x), y(y), z(z) {}

  Vertex(const Vertex &vertex) : x(vertex.x), y(vertex.y), z(vertex.z) {
    std::cout << "Copied!!" << std::endl;
  }
};

std::ostream &operator<<(std::ostream &stream, const Vertex &vertex) {
  stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
  return stream;
}

int main() {
  // not optimizing it
  std::vector<Vertex> vertices;
  vertices.push_back(
      {1, 2, 3});  // take to object allocated in the stack memory of the main
                   // function and copy it into the memory for the vector
  vertices.push_back(
      {4, 5, 6});  // enlarge the memory, copy the former and copy the newer.
  vertices.push_back({5, 6, 7});  // enlarge the memory, copy the two formers
                                  // and the newer. and so on.

  // optimizing it so does not copy objects.
  std::vector<Vertex> vertices2;
  vertices2.reserve(3);
  vertices2.emplace_back(
      1, 2, 3);  // take to object allocated in the stack memory of the main
                 // function and copy it into the memory for the vector
  vertices2.emplace_back(
      4, 5, 6);  // enlarge the memory, copy the former and copy the newer.
  vertices2.emplace_back(
      5, 6,
      7);  // enlarge the memory, copy the two formers and the newer. and so on.

  for (int i = 0; i < vertices.size(); i++) {
    std::cout << vertices[i] << std::endl;
  }

  for (Vertex v :
       vertices)  // this example is copying the data into v in every iteration
    std::cout << v << std::endl;

  for (Vertex &v :
       vertices)  // this example is not copying just taking the reference
    std::cout << v << std::endl;

  vertices.erase(vertices.begin() + 1);

  for (Vertex &v :
       vertices)  // this example is not copying just taking the reference
    std::cout << v << std::endl;

  vertices.clear();

  for (Vertex &v :
       vertices)  // this example is not copying just taking the reference
    std::cout << v << std::endl;
}