#include "bricks_game.h"
#include "gtest/gtest.h"

using bricks_game::determineWinner;
using std::string;

TEST(BricksGame, oneBrickGame) { 










EXPECT_EQ("Patlu", determineWinner(1)); }

TEST(BricksGame, twoBrickGame) { EXPECT_EQ("Motu", determineWinner(2)); }

TEST(BricksGame, hackerEarthExample) { EXPECT_EQ("Motu", determineWinner(13)); }
