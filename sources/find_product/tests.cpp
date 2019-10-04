#include "find_product.h"
#include <cmath>
#include "gtest/gtest.h"

using find_product::computeProductModulo;
using std::vector;

TEST(FindProduct, simple) {
  EXPECT_EQ(120, computeProductModulo({1, 2, 3, 4, 5}));
}

TEST(FindProduct, beforeEdge) {
  EXPECT_EQ(1000000006, computeProductModulo({1, 1000000006}));
}

TEST(FindProduct, behindEdge) {
  EXPECT_EQ(0, computeProductModulo({1, 1000000007}));
}
