#include "binary_search.h"
#include "gtest/gtest.h"

using binary_searching::binary_search;
using std::vector;

TEST(CheckIfBinarySearch, returnsEndForEmptyCollection) {
  const int arbitrary_element = 13;
  const vector<int> empty_collection;

  EXPECT_EQ(end(empty_collection),
            binary_search(empty_collection, arbitrary_element));
}

TEST(CheckIfBinarySearch, canFindElementInOneElementCollection) {
  const int to_find = 69;
  const vector<int> collection = {to_find};

  EXPECT_EQ(begin(collection), binary_search(collection, to_find));
}

TEST(CheckIfBinarySearch, doesNotReportFalsePositives) {
  const int to_find = 666;
  const vector<int> collection = {3, 7, 33, 1000};

  EXPECT_EQ(end(collection), binary_search(collection, to_find));
}

TEST(CheckIfBinarySearch, canFoundElementIfInTheMiddleOfLargerCollection) {
  const int to_find = 77;
  const vector<int> collection = {-34, -77, 3, 77, 445, 543, 666};

  EXPECT_EQ(begin(collection) + 3, binary_search(collection, to_find));
}

TEST(CheckIfBinarySearch, canFoundElementInLargerCollection) {
  const int to_find = 54;
  const vector<int> collection = {34, 54, 495, 508, 609, 1000, 4044};

  EXPECT_EQ(begin(collection) + 1, binary_search(collection, to_find));
}
