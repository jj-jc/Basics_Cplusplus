#include <iostream>

struct Vector2 {
  float x, y;
};

struct Vector4 {
  float x, y, z, w;
  Vector2 &GetA() {
    return *(Vector2 *)&x;  // Return the reference to a Vector 2 ( so  includes
                            // x and y information)
  }
};

struct Vector4Prettier {
  union {
    struct {
      float x, y, z, w;
    };

    struct {
      float r, g, b, a;
    };

    struct {
      Vector2 v1, v2;
    };
  };

  // float p;
  // float x, y, z, w; // it is not possible to define the same names that in
  // the struct
};

struct Union {
  union {
    float a;
    int b;
  };
};

struct Test {};

void printVector2(const Vector2 &vector) {
  std::cout << vector.x << ", " << vector.y << std::endl;
}

int main() {
  Union u;  // this is a struct that stores a 4 byte of data, because it can
            // store a float.
  u.a = 2.0f;
  std::cout << u.a << ", " << u.b
            << std::endl;  // the information stored is ridden by a float
                           // pointer or by a int pointer
  std::cout << "Size of Union: " << sizeof(Union) << std::endl;
  std::cout << "Size of Test: " << sizeof(Test) << std::endl;

  Vector4Prettier vector4Prettier = {1.0f, 2.0f, 3.0f, 4.0f};
  vector4Prettier.x = 2.0f;
  std::cout << "Vector4Prettier.x: " << vector4Prettier.x << std::endl;
  std::cout << "Vector4Prettier.a: " << vector4Prettier.a << std::endl;
  // std::cout << "Vector4Prettier.v1: " << vector4Prettier.v1 << std::endl;
  printVector2(vector4Prettier.v1);
}