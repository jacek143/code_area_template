#include "duration.h"
#include "gtest/gtest.h"

using duration::computeDuration;
using std::string;

TEST(Duration, noDuration) {
  EXPECT_EQ("0 0", computeDuration({12, 34}, {12, 34}));
}

TEST(Duration, wholeHours) {
  EXPECT_EQ("4 0", computeDuration({13, 53}, {17, 53}));
}

TEST(Duration, differentMinutes) {
  EXPECT_EQ("0 45", computeDuration({7, 1}, {7, 46}));
}

TEST(Duration, hourChange) {
  EXPECT_EQ("0 10", computeDuration({4, 55}, {5, 5}));
}

TEST(Duration, dayChange) {
  EXPECT_EQ("0 13", computeDuration({23, 50}, {0, 3}));
}

TEST(Duration, hackerEarthExample) {
  EXPECT_EQ("0 30", computeDuration({1, 44}, {2, 14}));
}
