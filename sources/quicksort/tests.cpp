#include "quicksort.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using quicksorting::quicksort;
using std::vector;
using testing::ElementsAre;

TEST(CheckIfQuicksort, doesNotChangeEmptyCollection) {
  vector<int> to_sort;
  quicksort(to_sort);
  EXPECT_TRUE(to_sort.empty());
}

TEST(CheckIfQuicksort, doesNotChangeOneElementCollection) {
  vector<int> to_sort{69};
  quicksort(to_sort);
  EXPECT_THAT(to_sort, ElementsAre(69));
}

TEST(CheckIfQuicksort, sortsTwoElements) {
  vector<int> to_sort{17, 13};
  quicksort(to_sort);
  EXPECT_THAT(to_sort, ElementsAre(13, 17));
}

TEST(CheckIfQuicksort, doesNotChangeTwoSortedElementsCollection) {
  vector<int> to_sort{-5, 21};
  quicksort(to_sort);
  EXPECT_THAT(to_sort, ElementsAre(-5, 21));
}

TEST(CheckIfQuicksort, worksForMultipleElementsCollection) {
  vector<int> to_sort{-7, 8, -31, 4, 8, -20, 9};
  quicksort(to_sort);
  EXPECT_THAT(to_sort, ElementsAre(-31, -20, -7, 4, 8, 8, 9));
}
