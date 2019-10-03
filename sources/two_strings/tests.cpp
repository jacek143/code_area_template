#include "two_strings.h"
#include "gtest/gtest.h"

using two_strings::areEqual;

TEST(TwoStrings, exactlyTheSame) { EXPECT_TRUE(areEqual("foobar", "foobar")); }

TEST(TwoStrings, completelyDifferent) { EXPECT_FALSE(areEqual("foo", "bar")); }

TEST(TwoStrings, validPermutation) { EXPECT_TRUE(areEqual("valid", "vladi")); }
