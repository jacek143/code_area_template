#include "common_denominators.h"
#include "gtest/gtest.h"

using Fracts::convertFrac;
using Fracts::smallestCommonDenominator;
using Fracts::smallestCommonMultiple;

TEST(CommonDenominatorsTests, simplifyOneRational) {
  EXPECT_EQ("(1,3)", convertFrac({{3, 9}}));
  EXPECT_EQ("(1,2)", convertFrac({{6, 12}}));
  EXPECT_EQ("(3,4)", convertFrac({{12, 16}}));
  EXPECT_EQ("(2,1)", convertFrac({{34, 17}}));
}

TEST(CommonDenominatorsTests, twoRationals) {
  EXPECT_EQ("(3,6)(2,6)", convertFrac({{1, 2}, {1, 3}}));
}

TEST(CommonDenominatorsTests, threeRationals) {
  EXPECT_EQ("(6,12)(4,12)(3,12)", convertFrac({{1, 2}, {1, 3}, {1, 4}}));
}

TEST(CommonDenominatorsTests, smallestCommonMultiple) {
  EXPECT_EQ(1, smallestCommonMultiple(1, 1));
  EXPECT_EQ(6, smallestCommonMultiple(2, 3));
  EXPECT_EQ(18, smallestCommonMultiple(6, 9));
  EXPECT_EQ(6, smallestCommonMultiple(3, 6));
  EXPECT_EQ(12, smallestCommonMultiple(12, 4));
}

TEST(CommonDenominatorsTests, smallestCommonDenominator) {
  EXPECT_EQ(18, smallestCommonDenominator({{1, 6}, {1, 9}}));
  EXPECT_EQ(6, smallestCommonDenominator({{1, 2}, {1, 3}}));
  EXPECT_EQ(12, smallestCommonDenominator({{1, 2}, {1, 3}, {1, 4}}));
}
