#include <iostream>
#include <memory>
#include <string>

class Investment {
 public:
  Investment();
  ~Investment();

 public:
  std::string name_{"Investment"};
  std::unique_ptr<Investment> makeInvestment();
};

class Stock : public Investment {};

class Bond : public Investment {};

class RealEstate : public Investment {};