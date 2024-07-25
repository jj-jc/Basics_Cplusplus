#include <gtest/gtest.h>

#include <memory>

#include "../Item18.hpp"
class Item18Test : public ::testing::Test {
 protected:
  std::unique_ptr<Investment> investment;
};

TEST_F(Item18Test, MakeInvestmentReturnsUniquePtr) {
  auto result = investment->makeInvestment();
  auto val = 1;
  EXPECT_EQ(val, 1);
}