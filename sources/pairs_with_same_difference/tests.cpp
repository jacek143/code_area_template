#include "pairs_with_same_difference.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using pairs_with_same_difference::get_pairs_with_same_diff;
using std::make_pair;
using testing::ElementsAre;

TEST(CheckIfFindingPairsWithSameDifference,
     canReturnValidPairFromTwoElemArray) {
  auto pairs = get_pairs_with_same_diff({4, 8}, 4);
  EXPECT_THAT(pairs, ElementsAre(make_pair(4, 8)));
}

TEST(CheckIfFindingPairsWithSameDifference, worksForBasicExample) {
  auto pairs = get_pairs_with_same_diff({45, 1, 7, 2, 5, 43, 6, 9, 13}, 2);
  EXPECT_THAT(pairs,
              ElementsAre(make_pair(5, 7), make_pair(7, 9), make_pair(43, 45)));
}
