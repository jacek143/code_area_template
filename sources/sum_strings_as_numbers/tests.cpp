#include "sum_strings_as_numbers.h"
#include "gtest/gtest.h"

using sum_strings_as_numbers::sum_strings;

TEST(CheckIfCanSumStrings, WhenSumOfRespectiveDigitsIsLessThen10) {
  EXPECT_EQ("5", sum_strings("3", "2"));
  EXPECT_EQ("26", sum_strings("14", "12"));
}

TEST(CheckIfCanSumStrings, ForBigNumbers) {
  EXPECT_EQ("390000000000", sum_strings("130000000000", "260000000000"));
}

TEST(CheckIfCanSumStrings, WhenSumOfDigitsIsBiggerThan9) {
  EXPECT_EQ("41", sum_strings("27", "14"));
  EXPECT_EQ("105", sum_strings("91", "14"));
}

TEST(CheckIfCanSumStrings, WhenSummedNumbersAreDifferentLength) {
  EXPECT_EQ("151", sum_strings("101", "50"));
  EXPECT_EQ("404", sum_strings("1", "403"));
}

TEST(CheckIfCanSumStrings, WhenThereAreAdditionalZerosInFront) {
  EXPECT_EQ("4", sum_strings("0002", "2"));
  EXPECT_EQ("4", sum_strings("2", "0000002"));
}

TEST(CheckIfCanSumStrings, WhenBothSumandsAreZeros) {
  EXPECT_EQ("0", sum_strings("0", "0"));
}
