#include "urlify_in_place.h"
#include "gtest/gtest.h"
#include <cstring>

using std::memcpy;
using testing::Test;
using urlify_in_place::buffer_t;
using urlify_in_place::urlify;

class CheckIfURLify : public Test {
public:
  void given_string(const char *string_to_urlify) {
    memcpy(buffer.data(), string_to_urlify, strlen(string_to_urlify) + 1);
  }
  void check_url(const char *url) {
    urlify(&buffer);
    EXPECT_STREQ(url, buffer.data());
  }
  buffer_t buffer = {'\0'};
};

TEST_F(CheckIfURLify, doesNotChangeEmptyStrings) {
  given_string("");
  check_url("");
}

TEST_F(CheckIfURLify, doesNotChangeStringsWithoutnew_length) {
  given_string("foobar");
  check_url("foobar");
}

TEST_F(CheckIfURLify, changesStringsWithOneSpace) {
  given_string("easy peasy");
  check_url("easy%20peasy");
}

TEST_F(CheckIfURLify, worksForSingleSpaceOnly) {
  given_string(" ");
  check_url("%20");
}

TEST_F(CheckIfURLify, worksForMultiplenew_length) {
  given_string("easy peasy lemon squeeze");
  check_url("easy%20peasy%20lemon%20squeeze");
}

TEST_F(CheckIfURLify, worksFornew_lengthOnTheEnd) {
  given_string("fu  ");
  check_url("fu%20%20");
}
