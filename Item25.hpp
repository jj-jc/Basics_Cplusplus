/**
 * @file Item25.hpp
 * @author Juan José Jurado Camino (juanjosejuradocamino@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <chrono>
#include <iostream>
#include <memory>
#include <set>

#include "spdlog/spdlog.h"

std::multiset<std::string> names;

/**
 * @brief Provides a simple Widget class with a name and a shared pointer.
 *
 * The Widget class has two member functions for setting the name:
 * - `SetName` uses `std::move` to move the new name into the `name` member.
 * - `SetNameCorrectly` uses `std::forward` to perfectly forward the new name
 * into the `name` member.
 */
class Widget {
 public:
  template <class T>
  void SetName(T&& newName) {
    ///< Universal reference it should use std::forward instead.
    name = std::move(newName);
  }
  template <class T>
  void SetNameCorrectly(T&& newName) {
    ///< Universal reference so it is using std::forward
    name = std::forward<T>(newName);
  }

 public:
  std::string name{"Name"};
  std::shared_ptr<int> p;
};

/**
 * @brief Overloads the + operator to concatenate the names of two Widget
 * objects.
 *
 * This function takes two Widget objects, `lhs` and `rhs`, and returns a new
 * Widget object with its `name` member set to the concatenation of the `name`
 * members of the input Widgets. The `lhs` Widget is moved into the returned
 * Widget to avoid unnecessary copying.
 *
 * @param lhs The left-hand side Widget object.
 * @param rhs The right-hand side Widget object.
 * @return A new Widget object with the concatenated names.
 */
Widget operator+(Widget& lhs, const Widget& rhs) {
  lhs.name += rhs.name;
  return std::move(lhs);
}

/**
 * @brief Overloads the + operator to concatenate the names of two Widget
 * objects.
 *
 * This function takes two Widget objects, `lhs` and `rhs`, and returns a new
 * Widget object with its `name` member set to the concatenation of the `name`
 * members of the input Widgets. The `lhs` Widget is moved into the returned
 * Widget to avoid unnecessary copying.
 *
 * @param lhs The left-hand side Widget object.
 * @param rhs The right-hand side Widget object.
 * @return A new Widget object with the concatenated names.
 */
Widget operator+(Widget&& lhs, const Widget& rhs) {
  lhs.name += rhs.name;
  return std::move(lhs);
}

void logAndAdd(const std::string& name) {
  spdlog::info("Added name: {}", name);
  names.emplace(name);
}

/**
 * @brief Logs the addition of a name and adds it to the `names` container.
 *
 * This function takes a name, logs it using `spdlog::info()`, and adds it to
 * the `names` container using `names.emplace()`. The name is forwarded using
 * `std::forward<T>()` to preserve its value category.
 *
 * @tparam T The type of the name parameter, which can be deduced automatically.
 * @param name The name to be added.
 */
template <class T>
void logAndAddImprovement(T&& name) {
  spdlog::info("Added name: {}", name);
  // Due to universal reference it is possible to change some behaviour and move
  // every time name is an rvalue
  names.emplace(std::forward<T>(name));
}