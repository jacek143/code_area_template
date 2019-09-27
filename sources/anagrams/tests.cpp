#include "gtest/gtest.h"
#include "anagrams.h"

using std::string;

TEST(Anagrams, alreadyAnagrams)
{
    EXPECT_EQ(0, getNumberOfDeletionsToMakeAnagrams("abc", "acb"));
}

TEST(Anagrams, oneDeletion)
{
    EXPECT_EQ(1, getNumberOfDeletionsToMakeAnagrams("abc", "abcd"));
}

TEST(Anagrams, argumentOrderDoesNotMatter)
{
    EXPECT_EQ(1, getNumberOfDeletionsToMakeAnagrams("abcd", "abc"));
}

TEST(Anagrams, onlyPartialOverlap)
{
    EXPECT_EQ(4, getNumberOfDeletionsToMakeAnagrams("abcd", "cdef"));
}

TEST(Anagrams, hackerEarthTest)
{
    EXPECT_EQ(4, getNumberOfDeletionsToMakeAnagrams("cde", "abc"));
}
