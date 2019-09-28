#include "gtest/gtest.h"
#include "split_houses.h"

using split_houses::splitHouses;
using std::string;

TEST(SplitHouses, notPossible)
{
    EXPECT_EQ("", splitHouses("HH"));
}

TEST(SplitHouses, oneFence)
{
    EXPECT_EQ("HBH", splitHouses("H.H"));
}
