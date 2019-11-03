#include "range_extraction.h"
#include "gtest/gtest.h"

TEST(RangeExtraction, noData) {
  EXPECT_EQ("", range_extraction::range_extraction({}));
}

TEST(RangeExtraction, oneNumber) {
  EXPECT_EQ("13", range_extraction::range_extraction({13}));
}

TEST(RangeExtraction, twoDistantNumbers) {
  EXPECT_EQ("3,17", range_extraction::range_extraction({3, 17}));
}

TEST(RangeExtraction, twoNearNumbers) {
  EXPECT_EQ("6,7", range_extraction::range_extraction({6, 7}));
}

TEST(RangeExtraction, range) {
  EXPECT_EQ("8-10", range_extraction::range_extraction({8, 9, 10}));
}

TEST(RangeExtraction, twoRanges) {
  EXPECT_EQ("1-3,7,10-12",
            range_extraction::range_extraction({1, 2, 3, 7, 10, 11, 12}));
}

TEST(RangeExtraction, codeWarsExample) {
  EXPECT_EQ("-6,-3-1,3-5,7-11,14,15,17-20",
            range_extraction::range_extraction({-6, -3, -2, -1, 0,  1,  3,
                                                4,  5,  7,  8,  9,  10, 11,
                                                14, 15, 17, 18, 19, 20}));
}
