/**
 * @file Item18.hpp
 * @author Juan José Jurado Camino (juanjosejuradocamino@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <memory>
#include <string>

class Investment {
 public:
  virtual ~Investment() = default;

  virtual std::unique_ptr<Investment> makeInvestment();
  virtual void printName() {
    std::cout << "Investment::" << this->name_ << std::endl;
  }

 public:
  std::string name_{"Investment"};
};

class Stock : public Investment {
 public:
  Stock();
  ~Stock() override = default;

  std::unique_ptr<Investment> makeInvestment() override;
  void printName() override { std::cout << "Stock" << name_ << std::endl; }

 public:
  std::string name_{"Stock"};
};

class Bond : public Investment {
 public:
  ~Bond() override = default;

  std::unique_ptr<Investment> makeInvestment() override;
  void printName() override { std::cout << "Bond::" << name_ << std::endl; }

 public:
  std::string name_{"Bond"};
};

class RealEstate : public Investment {
 public:
  ~RealEstate() override = default;

 public:
  std::string name_{"Real Estate"};
};