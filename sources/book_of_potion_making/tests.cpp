#include "book_of_potion_making.h"
#include "gtest/gtest.h"

using book_of_potion_making::validateIsbn;

TEST(BookOfPotionMaking, validExamples) {
  EXPECT_TRUE(validateIsbn("1000000001"));
  EXPECT_TRUE(validateIsbn("0100000010"));
  EXPECT_TRUE(validateIsbn("1401601499"));
}

TEST(BookOfPotionMaking, wrongLength) {
  EXPECT_FALSE(validateIsbn(""));
  EXPECT_FALSE(validateIsbn("010000001"));
  EXPECT_FALSE(validateIsbn("01000000100"));
}

TEST(BookOfPotionMaking, wrongChecksum) {
  EXPECT_FALSE(validateIsbn("0100000000"));
}
