#include "dislikes_and_party.h"
#include "gtest/gtest.h"

using std::istringstream;

TEST(DislikesAndParty, CheckIfParsingInputDataWorks) {
  istringstream input(
      "11\n7 3 11 4 5 6 1 2 8 9\n 1 11 10 5 6 8 3 7 4 2\n 9 3 2 7 5 8 10 4 1 "
      "11\n 8 2 5 10 3 6 4 7 9 1\n 3 10 2 11 7 9 1 5 6 4\n 5 11 1 3 8 10 4 6 2 "
      "9\n 11 1 8 7 3 2 10 6 5 9\n 4 1 5 11 10 6 3 2 9 7\n 2 1 9 11 8 6 7 10 3 "
      "4\n 10 5 4 1 3 6 2 11 7 8 ");
  uint64_t expected_friends = 11;
  dislike_matrix_t expected_dislike_matrix = {
      {7, 3, 11, 4, 5, 6, 1, 2, 8, 9},  {1, 11, 10, 5, 6, 8, 3, 7, 4, 2},
      {9, 3, 2, 7, 5, 8, 10, 4, 1, 11}, {8, 2, 5, 10, 3, 6, 4, 7, 9, 1},
      {3, 10, 2, 11, 7, 9, 1, 5, 6, 4}, {5, 11, 1, 3, 8, 10, 4, 6, 2, 9},
      {11, 1, 8, 7, 3, 2, 10, 6, 5, 9}, {4, 1, 5, 11, 10, 6, 3, 2, 9, 7},
      {2, 1, 9, 11, 8, 6, 7, 10, 3, 4}, {10, 5, 4, 1, 3, 6, 2, 11, 7, 8}};

  EXPECT_EQ(expected_friends, read_friends(input));
  EXPECT_EQ(expected_dislike_matrix, read_dislike_matrix(input));
}

TEST(DislikesAndParty, CheckIfCountingImpossibleHandshakesWorks) {
  dislike_matrix_t dislike_matrix = {{4, 5, 6}, {6, 4, 9}};
  // impossible handshakes: (4,5), (4,6), (6,9)
  EXPECT_EQ(3, count_impossible_handshakes(dislike_matrix));
}

TEST(DislikesAndParty, CheckIfCountingHandshakesWorks) {
  uint64_t friends = 10;
  dislike_matrix_t dislike_matrix = {{4, 5, 6}, {6, 4, 9}};

  uint64_t pairs = (friends * (friends - 1)) / 2;
  uint64_t impossible_handshakes =
      3; // impossible handshakes: (4,5), (4,6), (6,9)
  uint64_t expected = pairs - impossible_handshakes;

  EXPECT_EQ(expected, count_handshakes(friends, dislike_matrix));
}

TEST(DislikesAndParty, CheckIfParsingIsGluedWithComputation) {
  uint64_t friends = 11;
  dislike_matrix_t dislike_matrix = {
      {7, 3, 11, 4, 5, 6, 1, 2, 8, 9},  {1, 11, 10, 5, 6, 8, 3, 7, 4, 2},
      {9, 3, 2, 7, 5, 8, 10, 4, 1, 11}, {8, 2, 5, 10, 3, 6, 4, 7, 9, 1},
      {3, 10, 2, 11, 7, 9, 1, 5, 6, 4}, {5, 11, 1, 3, 8, 10, 4, 6, 2, 9},
      {11, 1, 8, 7, 3, 2, 10, 6, 5, 9}, {4, 1, 5, 11, 10, 6, 3, 2, 9, 7},
      {2, 1, 9, 11, 8, 6, 7, 10, 3, 4}, {10, 5, 4, 1, 3, 6, 2, 11, 7, 8}};
  istringstream stream(
      "11\n7 3 11 4 5 6 1 2 8 9\n 1 11 10 5 6 8 3 7 4 2\n 9 3 2 7 5 8 10 4 1 "
      "11\n 8 2 5 10 3 6 4 7 9 1\n 3 10 2 11 7 9 1 5 6 4\n 5 11 1 3 8 10 4 6 2 "
      "9\n 11 1 8 7 3 2 10 6 5 9\n 4 1 5 11 10 6 3 2 9 7\n 2 1 9 11 8 6 7 10 3 "
      "4\n 10 5 4 1 3 6 2 11 7 8 ");

  EXPECT_EQ(count_handshakes(stream),
            count_handshakes(friends, dislike_matrix));
}
