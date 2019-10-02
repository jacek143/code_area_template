#include "toggle_string.h"
#include "gtest/gtest.h"

using std::string;
using toggle_string::toggleString;

TEST(ToggleString, signature) {
  string input;
  string output = toggleString(input);
}

TEST(ToggleString, standardCase) { EXPECT_EQ("DuPA", toggleString("dUpa")); }
