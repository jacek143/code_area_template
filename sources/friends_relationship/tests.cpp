#include "friends_relationship.h"
#include "gtest/gtest.h"

using friends_relationship::generatePatter;
using std::endl;
using std::stringstream;

TEST(FriendsRelationship, shortestHackerEarthExample) {
  stringstream expected_pattern;
  expected_pattern << "*##*" << endl;
  expected_pattern << "****" << endl;
  EXPECT_EQ(expected_pattern.str(), generatePatter(2));
}

TEST(FriendsRelationship, mediumHackerEarthExample) {
  stringstream expected_pattern;
  expected_pattern << "*########*" << endl;
  expected_pattern << "**######**" << endl;
  expected_pattern << "***####***" << endl;
  expected_pattern << "****##****" << endl;
  expected_pattern << "**********" << endl;
  EXPECT_EQ(expected_pattern.str(), generatePatter(5));
}
