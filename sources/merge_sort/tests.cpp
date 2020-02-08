#include "merge_sort.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using merge_sorting::merge;
using merge_sorting::merge_sort;
using testing::ElementsAre;

TEST(CheckIfMergeSortWorks, forZeroElementCollection) {
  EXPECT_TRUE(merge_sort({}).empty());
}

TEST(CheckIfMergeSortWorks, forOneElementVector) {
  EXPECT_THAT(merge_sort({13}), ElementsAre(13));
}

TEST(CheckIfMergeSortWorks, forMultipleElements) {
  EXPECT_THAT(merge_sort({88, 3, -4, 100, 57, 29, 40}),
              ElementsAre(-4, 3, 29, 40, 57, 88, 100));
}

TEST(CheckIfMergeFunctionWorks, forOneElementVectors) {
  EXPECT_THAT(merge({15}, {20}), ElementsAre(15, 20));
  EXPECT_THAT(merge({20}, {15}), ElementsAre(15, 20));
}

TEST(CheckIfMergeFunctionWorks, forVectorsWithMultipleElements) {
  EXPECT_THAT(merge({-6, -2, 22, 50}, {0, 13, 35}),
              ElementsAre(-6, -2, 0, 13, 22, 35, 50));
}
