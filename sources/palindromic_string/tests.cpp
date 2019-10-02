#include "palindromic_string.h"
#include "gtest/gtest.h"

using palindromic_string::isPalindrome;
using std::string;

TEST(PalindromicString, simpleYes) { EXPECT_TRUE(isPalindrome("aba")); }

TEST(PalindromicString, simpleNo) { EXPECT_FALSE(isPalindrome("abac")); }
