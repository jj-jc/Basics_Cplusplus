/**
 * @file Item31Test.cpp
 * @author Juan José Jurado Camino (juanjosejuradocamino@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <gtest/gtest.h>

#include "../Lambda.hpp"
#include "spdlog/spdlog.h"

using FilterContainer = std::vector<std::function<bool(int)>>;
FilterContainer filters;

void doSomething(int value) {
  auto divisor = 5;
  filters.emplace_back(
      [](int value) { return value % 5 == 0; });  ///< No capturing any variable
  filters.emplace_back([&](int value) {
    return value % divisor == 0;
  });  ///< Capturing by reference any variable in the scope
  filters.emplace_back([=](int value) {  // This is not a good practice but it
                                         // divisor wont dangle.
    return value % divisor == 0;
  });  ///< Capturing by value any variable in the scope
  filters.emplace_back([&divisor](int value) {
    return value % divisor == 0;
  });  ///< Capturing by explicitaly by reference divisor variable
  filters.emplace_back([divisor](int value) {
    return value % divisor == 0;
  });  ///< Capturing explicitaly by value divisor variable
  spdlog::info("{}", divisor);
}

int func(int x, int y) { return x + y; };

/// @brief Test for understand lambdas correctly.
TEST(Lambda, Item31) {
  spdlog::info("Testing Lambda");
  // auto lambdaVariable = [capture list](parameters) -> return_type { body }
  doSomething(10);

  EXPECT_EQ(filters[0](10), true);
  EXPECT_EQ(filters[1](10), false);  // division reference is out of scope
  EXPECT_EQ(filters[2](10), true);
  EXPECT_EQ(filters[3](10), false);  // division refrence is aout of scope
  EXPECT_EQ(filters[4](10), true);
}

TEST(Lambda, Item32) {
  spdlog::info("Testing init capture or generalized lambda capture");
  auto pw = std::make_unique<Widget>();

  auto func = [pw = std::move(pw)] {  // init data mbr in closure (init capture
                                      // or generalized lambda capture)
    return pw->IsValidated() && pw->IsArchived();
  };

  auto func2 = [pw = std::make_unique<Widget>()] {
    return pw->IsValidated() && pw->IsArchived();
  };

  EXPECT_EQ(func(), true);
  EXPECT_EQ(func2(), true);
}

TEST(Lambda, Item33) {
  spdlog::info("Testing generic lambdas");
  // auto func = [](auto a, auto b) { return a + b; }; //Simply are lambdas that
  // use auto in their parameters.
  auto function = [](auto a, auto b) { return a + b; };

  auto perfectForwarding = [](auto&&... params) {
    return func(std::forward<decltype(params)>(params)...);
  };

  EXPECT_EQ(function(1, 2), 3);
  EXPECT_EQ(perfectForwarding(1, 2), 3);
}
