#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

class Timer {
 public:
  std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
  std::chrono::duration<float> duration;

  Timer() { start = std::chrono::high_resolution_clock::now(); }

  ~Timer() {
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    float ms = duration.count() * 1000.0f;
    std::cout << "Timer took " << ms << "ms" << std::endl;
    // std::cout << "Timer took " << duration.count() << "ms" << std::endl;
  }
};

int main() {
  while (1) {
    int *array = new int[50];  // allocate 200 bytes of memory (for 50 ints)
    delete[] array;

    std::cout << "Multiple arrays: ";
    {
      Timer timer;
      // Creating a multidimensional array with new
      int **a2d = new int
          *[50];  // allocate 200 bytes of memoery ( for 50 integerpointers)
      for (int i = 0; i < 50; i++) a2d[i] = new int[50];

      // accessing to multidimensional array
      for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 50; x++) {
          a2d[x][y] = x;
        }
      }

      // Deleting a multidimensional array with delete
      for (int i = 0; i < 50; i++)
        delete[] a2d[i];  // this is very important to take into account, you
                          // have to delete every array of integers.
      delete[] a2d;  // and of course you have to delete the array of pointers.
    }

    std::cout << "Multiple elements: ";
    {
      Timer time;
      int *b2d = new int[50 * 50];
      for (int x = 0; x < 50; x++) {
        for (int y = 0; y < 50; y++) {
          b2d[x * 50 + y];
        }
      }
      delete[] b2d;
    }
  }
}
