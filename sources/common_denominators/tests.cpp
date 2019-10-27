#include "common_denominators.h"
#include "gtest/gtest.h"

using Fracts::convertFrac;
using std::vector;

using Rationals = vector<vector<unsigned long long>>;

TEST(CommonDenominatorsTests, onlyOneRational) {
  const Rationals rationals = {{1, 2}};
  EXPECT_EQ("(1,2)", convertFrac(rationals));
}
