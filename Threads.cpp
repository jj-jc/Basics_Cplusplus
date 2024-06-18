
#include <iostream>
#include <string>
#include <thread>
#include <vector>

static bool s_Finished = false;

void doWork() {
  using namespace std::literals::chrono_literals;  // to let 1s in the sleep_for
                                                   // funcion

  std::cout << "Started thread id = " << std::this_thread::get_id()
            << std::endl;

  while (!s_Finished) {
    std::cout << "Working ..." << std::endl;
    std::this_thread::sleep_for((1s));
  }
}

int main() {
  std::thread worker(
      doWork);  // create a thread that execute with function pointers

  std::cin.get();

  s_Finished = true;

  worker.join();  // wait for the thread worker to finish its work. Block the
                  // current thread till the worker thread is finished,
  std::cout << "Finish ..." << std::endl;
  std::cout << "Started thread id = " << std::this_thread::get_id()
            << std::endl;
}