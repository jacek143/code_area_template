#include "gtest/gtest.h"
#include "palindromic_string.h"

using std::string;
using palindromic_string::isPalindrome;

TEST(PalindromicString, signature)
{
    string input = "";
    bool answer = isPalindrome(input);
}

TEST(PalindromicString, simpleYes)
{
    EXPECT_TRUE(isPalindrome("aba"));
}

TEST(PalindromicString, simpleNo)
{
    EXPECT_FALSE(isPalindrome("abac"));
}
