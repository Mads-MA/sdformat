/*
 * Copyright (C) 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <gtest/gtest.h>
#include "sdf/Gui.hh"

/////////////////////////////////////////////////
TEST(DOMGui, Construction)
{
  sdf::Gui gui;
  EXPECT_FALSE(gui.Fullscreen());
  EXPECT_EQ(nullptr, gui.Element());
}

/////////////////////////////////////////////////
TEST(DOMGui, CopyConstruction)
{
  sdf::ElementPtr sdf(std::make_shared<sdf::Element>());

  sdf::Gui gui;
  gui.Load(sdf);
  gui.SetFullscreen(true);
  EXPECT_TRUE(gui.Fullscreen());

  sdf::Gui gui2(gui);
  EXPECT_TRUE(gui2.Fullscreen());
  EXPECT_NE(nullptr, gui2.Element());
  EXPECT_EQ(gui.Element(), gui2.Element());
}

/////////////////////////////////////////////////
TEST(DOMGui, MoveConstruction)
{
  sdf::Gui gui;
  gui.SetFullscreen(true);
  EXPECT_TRUE(gui.Fullscreen());

  sdf::Gui gui2(std::move(gui));
  EXPECT_TRUE(gui2.Fullscreen());
}

/////////////////////////////////////////////////
TEST(DOMGui, Set)
{
  sdf::Gui gui;
  gui.SetFullscreen(true);
  EXPECT_TRUE(gui.Fullscreen());
}

/////////////////////////////////////////////////
TEST(DOMGui, Equal)
{
  sdf::Gui gui;
  gui.SetFullscreen(true);
  sdf::Gui gui2(gui);

  EXPECT_TRUE(gui == gui2);
  gui.SetFullscreen(false);
  EXPECT_FALSE(gui == gui2);
}
