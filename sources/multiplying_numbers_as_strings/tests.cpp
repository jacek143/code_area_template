#include "multiplying_numbers_as_strings.h"
#include "gtest/gtest.h"

using string_math::add;
using string_math::multiply;

TEST(CheckIfCanMultiply, smallNumbers) {
  EXPECT_EQ("6", multiply("2", "3"));
  EXPECT_EQ("8", multiply("4", "2"));
}

TEST(CheckIfCanMultiply, bigNumberByOne) {
  EXPECT_EQ("1000000000000", multiply("1", "1000000000000"));
  EXPECT_EQ("12345678987654321", multiply("12345678987654321", "1"));
}

TEST(CheckIfCanMultiply, bigNumberBySingleDigitNumberWithoutOverflow) {
  EXPECT_EQ("6280000000000", multiply("3140000000000", "2"));
}

TEST(CheckIfCanMultiply, bigNumberBySingleDigitNumberWithOverflow) {
  EXPECT_EQ("15000000000012", multiply("3", "5000000000004"));
}

TEST(CheckIfCanMultiply, byZero) {
  EXPECT_EQ("0", multiply("0", "395000005494053400384"));
}

TEST(CheckIfCanMultiply, multiDigitNumberByEachOther) {
  EXPECT_EQ("121", multiply("11", "11"));
}

TEST(CheckIfCanMultiply, andIgnoreLeadingZeros) {
  EXPECT_EQ("3", multiply("3", "0000001"));
}

TEST(CheckIfCanAdd, singleDigits) {
  EXPECT_EQ("9", add("3", "6"));
  EXPECT_EQ("12", add("6", "6"));
}

TEST(CheckIfCanAdd, singleDigitToBigNumber) {
  EXPECT_EQ("1000000000000000000000000000009",
            add("1000000000000000000000000000000", "9"));
}
