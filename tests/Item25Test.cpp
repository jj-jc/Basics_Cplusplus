/**
 * @file Item25Test.cpp
 * @author Juan José Jurado Camino (juanjosejuradocamino@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <gtest/gtest.h>

#include "../Item25.hpp"

TEST(Item25, universalReferences) {
  Widget widget;
  widget.SetName("Hola");

  EXPECT_EQ(widget.name, "Hola");

  std::string newName = "Mundo";
  widget.SetName(newName);

  EXPECT_EQ(widget.name, "Mundo");
  EXPECT_NE(newName, "Mundo");  ///< This is because SetName is casting newName
                                ///< variable to an rvalue so it is lost.
  newName = "Nuevo Mundo";
  widget.SetNameCorrectly(newName);
  EXPECT_EQ(newName, "Nuevo Mundo");
}

TEST(Item25, operators) {
  Widget widget;
  widget.SetName("Hola");
  Widget widget2;
  widget.name = "Hola";
  widget2.name = " Mundo!";

  Widget widgetSum = widget + widget2;
  EXPECT_EQ(widgetSum.name, "Hola Mundo!");
  EXPECT_EQ(widget.name, "");
  EXPECT_EQ(widget2.name, " Mundo!");

  widgetSum = Widget() + widget2;
  EXPECT_EQ(widgetSum.name, "Name Mundo!");
}

TEST(Item25, spdlog) {
  spdlog::info("Welcome to spdlog!");
  spdlog::error("Some error message with arg: {}", 1);
  spdlog::debug("This message should not be displayed..");
  spdlog::set_level(spdlog::level::debug);  // Set global log level to debug
  spdlog::debug("This message should be displayed..");

  SPDLOG_TRACE("Some trace message with param {}", 42);
  SPDLOG_DEBUG("Some debug message");
}

TEST(Item25, logAndAdd) {
  std::string text = "Text";
  logAndAdd(text);
  logAndAdd(std::string("Text2"));
  logAndAdd("Text3");
}