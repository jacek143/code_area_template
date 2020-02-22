#include "check_string_permutation.h"
#include "gtest/gtest.h"

using check_string_permutation::are_permutations;

TEST(CheckIfCheckingAgainstStringPermutations,
     returnsTrueForTwoSingleCharacter) {
  EXPECT_TRUE(are_permutations("g", "g"));
}

TEST(CheckIfCheckingAgainstStringPermutations,
     returnsFalseForTwoDifferentSingleCharacter) {
  EXPECT_FALSE(are_permutations("h", "z"));
}

TEST(CheckIfCheckingAgainstStringPermutations,
     returnsTrueForMulticharacterPermutations) {
  EXPECT_TRUE(are_permutations("foobar", "arfobo"));
}

TEST(CheckIfCheckingAgainstStringPermutations,
     returnsFalseForStringNotBeeingPermutations) {
  EXPECT_FALSE(are_permutations("foobar", "arffbo"));
}
