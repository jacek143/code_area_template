#include "almond_problem.h"
#include "gtest/gtest.h"

using almond_problem::compute_days_of_consumption;
using testing::Test;

class CheckIfAlmondProblemAnalyzer : public Test {
public:
  void EXPECT_DAYS(int expected) {
    int actual = compute_days_of_consumption(initial_amount, consumption_rate,
                                             restoration_rate);
    EXPECT_EQ(expected, actual);
  }
  unsigned initial_amount = 0;
  unsigned consumption_rate = 0;
  unsigned restoration_rate = 0;
};

TEST_F(CheckIfAlmondProblemAnalyzer, canDetectObviousInfiniteConsumption) {
  initial_amount = 10;
  consumption_rate = 1;
  restoration_rate = 2;
  EXPECT_DAYS(-1);
}

TEST_F(CheckIfAlmondProblemAnalyzer, canDetectInfiniteConsumptionOnTheEdge) {
  initial_amount = 3;
  consumption_rate = 3;
  restoration_rate = 3;
  EXPECT_DAYS(-1);
}

TEST_F(CheckIfAlmondProblemAnalyzer,
       canDetectWhenAliceEatsTooMuchFromTheStart) {
  initial_amount = 5;
  consumption_rate = 6;
  restoration_rate = 10;
  EXPECT_DAYS(0);
}

TEST_F(CheckIfAlmondProblemAnalyzer, canSolveSimpleExample) {
  initial_amount = 2;
  consumption_rate = 2;
  restoration_rate = 1;
  EXPECT_DAYS(1);
}

TEST_F(CheckIfAlmondProblemAnalyzer, conComputeTypicalProblem) {
  initial_amount = 12;
  consumption_rate = 4;
  restoration_rate = 2;
  // 12 -start
  // 8 after first consumption
  // 6 after second consumption
  // 4 after third consumption
  // 2 after fourth consumption
  // 0 after fifith consumption
  EXPECT_DAYS(5);
}

TEST_F(CheckIfAlmondProblemAnalyzer, conComputeTypicalProblem2) {
  initial_amount = 14;
  consumption_rate = 4;
  restoration_rate = 3;
  // 14 -start
  // 10 after first consumption
  // 9 after second consumption
  // 8 after third consumption
  // ...
  // 0 after 11th consumption
  EXPECT_DAYS(11);
}
