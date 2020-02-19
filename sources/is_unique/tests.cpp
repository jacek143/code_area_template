#include "is_unique.h"
#include "gtest/gtest.h"
#include <unordered_set>

using std::string;
using std::unordered_set;
using string_uniqueness::is_unique;
using string_uniqueness::UniqueCharacterSet;
using testing::Test;

class CheckIfIsUnique : public Test {
public:
  void EXPECT_UNIQUENESS(const string &word, bool uniqueness) {
    EXPECT_EQ(uniqueness, is_unique<UniqueCharacterSet>(word));
    EXPECT_EQ(uniqueness, is_unique<unordered_set<char>>(word));
  }
};

TEST_F(CheckIfIsUnique, returnsTrueForASingleCharacter) {
  EXPECT_UNIQUENESS("g", true);
}

TEST_F(CheckIfIsUnique, returnsFalseIfStringIsRepetationOfOneCharacter) {
  EXPECT_UNIQUENESS("ww", false);
}

TEST_F(CheckIfIsUnique, returnsTrueForLongerStringWithoutRepetitions) {
  EXPECT_UNIQUENESS("abcdefghijklmn", true);
}

TEST_F(CheckIfIsUnique, returnsFalseForLongerStringWithOneRepetitionOnly) {
  EXPECT_UNIQUENESS("abcdiefghijklmn", false);
}
