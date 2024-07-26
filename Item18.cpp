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
#include "Item18.hpp"

std::unique_ptr<Investment> Investment::makeInvestment() {
  std::cout << "This is the makeInvestment factory method!\n";
  auto pInv = std::make_unique<Investment>();
  return pInv;
}

std::unique_ptr<Investment> Stock::makeInvestment() {
  std::cout << "Stock - This is the makeInvestment factory method!\n";
  auto pInv = std::make_unique<Stock>();
  return pInv;
}

Stock::Stock() { Investment::name_ = "Stock"; }

std::unique_ptr<Investment> Bond::makeInvestment() {
  std::cout << "Bond - This is the makeInvestment factory method!\n";
  auto pInv = std::make_unique<Bond>();
  return pInv;
}
