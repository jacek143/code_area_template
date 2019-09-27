#include "gtest/gtest.h"
#include "factorial.h"

using factorial::computeFactorial;

TEST(Factorial, factorial0)
{

    EXPECT_EQ(1, computeFactorial(0));
}

TEST(Factorial, factorial1)
{
    EXPECT_EQ(1, computeFactorial(1));
}

TEST(Factorial, factorial2)
{
    EXPECT_EQ(2, computeFactorial(2));
}

TEST(Factorial, factorial8)
{
    EXPECT_EQ(40320, computeFactorial(8));
}
