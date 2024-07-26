#include <gtest/gtest.h>

#include <memory>

#include "../Item18.hpp"
class Item18Test : public ::testing::Test {
 protected:
  std::unique_ptr<Investment> investment;
};

TEST(Item18Test, CheckNameHiding) {
  auto investment = std::make_unique<Investment>();
  investment->printName();
  auto investment2 = investment->makeInvestment();
  investment2->printName();

  EXPECT_NE(investment, nullptr);
  EXPECT_NE(investment2, nullptr);

  auto stock = std::make_unique<Stock>();
  auto bond = std::make_unique<Bond>();
  auto realEstate = std::make_unique<RealEstate>();

  EXPECT_EQ(stock->name_, "Stock");
  EXPECT_EQ(bond->name_, "Bond");
  EXPECT_EQ(realEstate->name_, "Real Estate");
  EXPECT_EQ(stock->Investment::name_, "Stock");

  realEstate->printName();         ///< Use base method.
  stock->Investment::printName();  ///< Use base method. Due to name hiding uses
                                   ///< the stockes::name member
  dynamic_cast<Investment*>(stock.get())
      ->Investment::printName();  ///< This way is not possible neither

  stock->Investment::name_ = "New Investment";
  EXPECT_EQ(stock->Investment::name_, "New Investment");
}
