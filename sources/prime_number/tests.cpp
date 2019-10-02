#include "prime_number.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using prime_number::getPrimeNumbersTill;
using std::vector;
using ::testing::ElementsAre;

TEST(PrimeNumber, returnsNothingFor1) {
  EXPECT_TRUE(getPrimeNumbersTill(1).empty());
}

TEST(PrimeNumber, isCorrectFor2) {
  EXPECT_THAT(getPrimeNumbersTill(2), ElementsAre(2));
}

TEST(PrimeNumber, isCorrectFor15) {
  EXPECT_THAT(getPrimeNumbersTill(15), ElementsAre(2, 3, 5, 7, 11, 13));
}
