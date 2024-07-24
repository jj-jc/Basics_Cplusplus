/**
 * @file Item18.cpp
 * @author Juan José Jurado Camino (juanjosejuradocamino@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <memory>
#include <string>

class Investment {
  std::string name_{"Investment"};
  template <typename T>
  std::unique_ptr<Investment> makeInvestment(T&& param);
};

class Stock : public Investment {};

class Bond : public Investment {};

class RealEstate : public Investment {};

int main() {
  std::cout << "Hello Item18\n";

  return true;
}

template <typename T>
std::unique_ptr<Investment> Investment::makeInvestment(T&& param) {
  std::cout << "This is the makeInvestment factory method!\n";
  pInv = std::make_unique<Investment>();
  return pInv;
}