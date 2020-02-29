#include "palindrome_permutation.h"
#include "gtest/gtest.h"

using palindrome_permutation::chars_count_t;
using palindrome_permutation::count_characters;
using palindrome_permutation::find_palindromic_permutations;
using palindrome_permutation::generate_permutations;
using palindrome_permutation::unique_strings_t;
using std::string;
using testing::Test;

class CheckIfGenerationOfPalindromicPermutations : public Test {
public:
  unique_strings_t expected;
  void for_string_expect_palindromes(const string &input,
                                     const unique_strings_t &expected) {
    EXPECT_EQ(find_palindromic_permutations(input), expected);
  }
};

TEST_F(CheckIfGenerationOfPalindromicPermutations, worksForSingleCharacer) {
  for_string_expect_palindromes("a", {"a"});
}

TEST_F(CheckIfGenerationOfPalindromicPermutations,
       returnsEmptyListForStringsWithoutPalindrome) {
  for_string_expect_palindromes("abc", {});
}

TEST_F(CheckIfGenerationOfPalindromicPermutations,
       worksForStringWithSinglePalindromePermutation) {
  for_string_expect_palindromes("foo", {"ofo"});
}

TEST_F(CheckIfGenerationOfPalindromicPermutations,
       worksForStringsWithMultiplePalindromicPermutations) {
  for_string_expect_palindromes("tatoo", {"toaot", "otato"});
}

TEST_F(CheckIfGenerationOfPalindromicPermutations,
       worksForStringsWithOnlyPairedLetters) {
  for_string_expect_palindromes("mama", {"maam", "amma"});
}

TEST_F(CheckIfGenerationOfPalindromicPermutations, ignoresLettersCase) {
  for_string_expect_palindromes("Boo", {"obo"});
}

TEST(CheckIfGenerationOfPermutations, works) {
  unique_strings_t expected{"abc", "acb", "bac", "bca", "cab", "cba"};
  EXPECT_EQ(generate_permutations("abc"), expected);
}

TEST(CheckIfCountingCharacters, works) {
  chars_count_t actual = count_characters("foobar");
  chars_count_t expected{{'a', 1}, {'b', 1}, {'f', 1}, {'o', 2}, {'r', 1}};
  EXPECT_EQ(actual, expected);
}
