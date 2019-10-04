#include "roy_and_profile_picture.h"
#include "gtest/gtest.h"

using roy_and_profile_picture::checkPicture;
using roy_and_profile_picture::Result;
using std::string;

TEST(RoyAndProfilePicture, tooSmall) {
  EXPECT_EQ(Result::UPLOAD_ANOTHER, checkPicture(10, {5, 5}));
}

TEST(RoyAndProfilePicture, perfect) {
  EXPECT_EQ(Result::ACCEPTED, checkPicture(17, {17, 17}));
}

TEST(RoyAndProfilePicture, perfectAndBigger) {
  EXPECT_EQ(Result::ACCEPTED, checkPicture(17, {20, 20}));
}

TEST(RoyAndProfilePicture, notSquare) {
  EXPECT_EQ(Result::CROP_IT, checkPicture(17, {20, 28}));
}
