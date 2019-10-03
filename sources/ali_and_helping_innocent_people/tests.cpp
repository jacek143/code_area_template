#include "ali_and_helping_innocent_people.h"
#include "gtest/gtest.h"
#include <algorithm>

using ali_and_helping_innocent_people::isTagValid;
using std::find;
using std::string;
using std::vector;

class AliAndHelpingInnocentPeople : public ::testing::Test {
public:
  const vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'Y'};
  bool isVowel(char letter) const {
    return find(begin(vowels), end(vowels), letter) != vowels.end();
  }
};

TEST_F(AliAndHelpingInnocentPeople, validTag) {
  EXPECT_TRUE(isTagValid("22X222-22"));
  EXPECT_TRUE(isTagValid("33F759-13"));
  EXPECT_TRUE(isTagValid("13X357-22"));
}

TEST_F(AliAndHelpingInnocentPeople, invalidDueToVowels) {
  string tag = "62_462-48";
  for (auto &&letter : vowels) {
    tag[2] = letter;
    EXPECT_FALSE(isTagValid(tag));
  }
}

TEST_F(AliAndHelpingInnocentPeople, validBecauseNotVowels) {
  string tag = "82_622-88";
  for (char letter = 'A'; letter <= 'Z'; letter++) {
    tag[2] = letter;
    EXPECT_EQ(not isVowel(letter), isTagValid(tag));
  }
}

TEST_F(AliAndHelpingInnocentPeople, invalidDueSumOfConsecutiveDigitsNotEven) {
  EXPECT_FALSE(isTagValid("23G846-44"));
}
