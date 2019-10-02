#include "lift_queries.h"
#include "gtest/gtest.h"

using lift_queries::determineLift;
using lift_queries::Lifts;
using std::string;

class LiftQueries : public ::testing::Test {
protected:
  Lifts lifts;
};

TEST_F(LiftQueries, lastFloor) { EXPECT_EQ("B", lifts.queryForFloor(6)); }

TEST_F(LiftQueries, middleFloor) { EXPECT_EQ("A", lifts.queryForFloor(3)); }

TEST_F(LiftQueries, lowestB) { EXPECT_EQ("B", lifts.queryForFloor(4)); }

TEST_F(LiftQueries, groundFloor) { EXPECT_EQ("A", lifts.queryForFloor(0)); }

TEST_F(LiftQueries, multiQuery) {
  EXPECT_EQ("A", lifts.queryForFloor(3));
  EXPECT_EQ("A", lifts.queryForFloor(5));
}
