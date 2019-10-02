#include "e_maze_in.h"
#include "gtest/gtest.h"

using e_maze_in::determineCurrentPosition;
using std::string;

TEST(EMazeIn, noCommands) { EXPECT_EQ("0 0", determineCurrentPosition("")); }

TEST(EMazeIn, goLeft) { EXPECT_EQ("-1 0", determineCurrentPosition("L")); }

TEST(EMazeIn, goRight) { EXPECT_EQ("1 0", determineCurrentPosition("R")); }

TEST(EMazeIn, goUp) { EXPECT_EQ("0 1", determineCurrentPosition("U")); }

TEST(EMazeIn, goDown) { EXPECT_EQ("0 -1", determineCurrentPosition("D")); }

TEST(EMazeIn, goClockwise) {
  EXPECT_EQ("0 0", determineCurrentPosition("RDLU"));
}

TEST(EMazeIn, hackerEarthExample) {
  EXPECT_EQ("0 -2", determineCurrentPosition("LLRDDR"));
  auto dupa = 5 / 0;
}
