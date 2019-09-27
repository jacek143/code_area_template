#include "gtest/gtest.h"
#include "factorial.h"

TEST(Factorial, factorial0)
{
    EXPECT_EQ(1, factorial(0));
}

TEST(Factorial, factorial1)
{
    EXPECT_EQ(1, factorial(1));
}

TEST(Factorial, factorial2)
{
    EXPECT_EQ(2, factorial(2));
}

TEST(Factorial, factorial8)
{
    EXPECT_EQ(40320, factorial(8));
}
