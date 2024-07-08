/**
 * @file Item7.cpp
 * @author Juan José Jurado Camino (juanjosejuradocamino@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <atomic>
#include <iostream>

using namespace std;

int counts = {0};
class Widget {
 public:
  Widget() {
    cout << counts << ". Widget default constructor\n";
    counts++;
  }
  Widget(const Widget&) {
    cout << counts << ". Widget copy constructor\n";
    counts++;
  }
  Widget(int i, bool b) {
    cout << counts << ". Widget(int i, bool b) called\n";
    counts++;
  }
  Widget(std::initializer_list<long double> il) {
    cout << counts << ".Widget(std::initializer_list<long double> il) called\n";
    counts++;
  }
  operator float() const { return 32; }  ///< convert to float
  Widget& operator=(const Widget& widget) {
    cout << counts << ". Operator = called\n";
    counts++;
    return *this;
  }
  int x{0};   ///< Ok
  int y = 0;  ///< Ok
  //   int z(0);   ///< Not ok! Not default initialization proper way.
};

int main() {
  ///@brief All these are the same for the compiler
  int x(0);
  int y = 0;
  int z{0};
  int w = {0};

  ///@brief These are not built-in types so do not work the same way
  Widget w0;       ///< call default constructor
  Widget w1 = w0;  ///< not an assignment; calls copy ctor
  w0 = w1;         ///< an assignment; calls copy operator=

  std::atomic<int> ai1{0};  ///< One way to initialize uncopyable objects
  std::atomic<int> ai2(0);  ///< One way to initialize uncopyable objects

  double d1, d2, d3;
  int sum1{x + y + z};     ///< Error! sum of double may not be expressible as.
                           ///< That is working for the compiler
  int sum2(d1 + d2 + d3);  ///< This is posible and execute an implicit
                           ///< conversion from double to int.
  Widget widget3{10, true};  ///< Uses std::initializer_list parameter!!!
  Widget widget4(10, true);  ///< Uses ctor defined.
  Widget widget5{10, 4.5};   ///< Uses std::initializer_list parameter.

  Widget widget6(widget3);  ///< copy constuctor
  Widget widget7{
      widget3};  ///< wiget3 -> float -> long double -> std::initializer_list
  Widget widget8(move(widget3));  ///< calls copy constructor
  Widget widget9{move(widget3)};  ///< the same as widget 7
}