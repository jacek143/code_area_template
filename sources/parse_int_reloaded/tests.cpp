#include "parse_int_reloaded.h"
#include "gtest/gtest.h"

using parse_int_reloaded::parse_int;

TEST(ParseIntReloadedTests, invalidString) {
  EXPECT_EQ(0, parse_int("foobar"));
}

TEST(ParseIntReloadedTests, zero) { EXPECT_EQ(0, parse_int("zero")); }

TEST(ParseIntReloadedTests, one) { EXPECT_EQ(1, parse_int("one")); }

TEST(ParseIntReloadedTests, two) { EXPECT_EQ(2, parse_int("two")); }

TEST(ParseIntReloadedTests, three) { EXPECT_EQ(3, parse_int("three")); }

TEST(ParseIntReloadedTests, four) { EXPECT_EQ(4, parse_int("four")); }

TEST(ParseIntReloadedTests, five) { EXPECT_EQ(5, parse_int("five")); }

TEST(ParseIntReloadedTests, six) { EXPECT_EQ(6, parse_int("six")); }

TEST(ParseIntReloadedTests, seven) { EXPECT_EQ(7, parse_int("seven")); }

TEST(ParseIntReloadedTests, eight) { EXPECT_EQ(8, parse_int("eight")); }

TEST(ParseIntReloadedTests, nine) { EXPECT_EQ(9, parse_int("nine")); }

TEST(ParseIntReloadedTests, ten) { EXPECT_EQ(10, parse_int("ten")); }

TEST(ParseIntReloadedTests, eleven) { EXPECT_EQ(11, parse_int("eleven")); }

TEST(ParseIntReloadedTests, twelve) { EXPECT_EQ(12, parse_int("twelve")); }

TEST(ParseIntReloadedTests, thirteen) { EXPECT_EQ(13, parse_int("thirteen")); }

TEST(ParseIntReloadedTests, fourteen) { EXPECT_EQ(14, parse_int("fourteen")); }

TEST(ParseIntReloadedTests, fifteen) { EXPECT_EQ(15, parse_int("fifteen")); }

TEST(ParseIntReloadedTests, sixteen) { EXPECT_EQ(16, parse_int("sixteen")); }

TEST(ParseIntReloadedTests, seventeen) {
  EXPECT_EQ(17, parse_int("seventeen"));
}

TEST(ParseIntReloadedTests, eighteen) { EXPECT_EQ(18, parse_int("eighteen")); }

TEST(ParseIntReloadedTests, nineteen) { EXPECT_EQ(19, parse_int("nineteen")); }

TEST(ParseIntReloadedTests, twenty) { EXPECT_EQ(20, parse_int("twenty")); }

TEST(ParseIntReloadedTests, twentyFive) {
  EXPECT_EQ(25, parse_int("twenty-five"));
}

TEST(ParseIntReloadedTests, thirtyThree) {
  EXPECT_EQ(33, parse_int("thirty-three"));
}

TEST(ParseIntReloadedTests, fortySix) { EXPECT_EQ(46, parse_int("forty-six")); }

TEST(ParseIntReloadedTests, fiftyFive) {
  EXPECT_EQ(55, parse_int("fifty-five"));
}

TEST(ParseIntReloadedTests, sixtyNine) {
  EXPECT_EQ(69, parse_int("sixty-nine"));
}

TEST(ParseIntReloadedTests, seventyThree) {
  EXPECT_EQ(73, parse_int("seventy-three"));
}

TEST(ParseIntReloadedTests, eighty) { EXPECT_EQ(80, parse_int("eighty")); }

TEST(ParseIntReloadedTests, ninetyNine) {
  EXPECT_EQ(99, parse_int("ninety-nine"));
}

TEST(ParseIntReloadedTests, oneHundred) {
  EXPECT_EQ(100, parse_int("one hundred"));
}

TEST(ParseIntReloadedTests, ignoreAnd) {
  EXPECT_EQ(246, parse_int("two hundred and forty-six"));
}

TEST(ParseIntReloadedTests, nineThousand) {
  EXPECT_EQ(9000, parse_int("nine thousand"));
}

TEST(ParseIntReloadedTests, bothThousandAndHundredPresent) {
  EXPECT_EQ(6300, parse_int("six thousand three hundred"));
}

TEST(ParseIntReloadedTests, complexThousand) {
  EXPECT_EQ(26059, parse_int("twenty-six thousand fifty-nine"));
}

TEST(ParseIntReloadedTests, oneMillion) {
  EXPECT_EQ(1000000, parse_int("one million"));
}

TEST(ParseIntReloadedTests, complexMillion) {
  EXPECT_EQ(
      6543210,
      parse_int(
          "six million five hundred forty-three thousand two hundred ten"));
}
