#include "roy_and_profile_picture.h"
#include <algorithm>

using roy_and_profile_picture::PictureSize;
using roy_and_profile_picture::Result;
using std::min;

Result roy_and_profile_picture::checkPicture(unsigned min_length,
                                             PictureSize picture_size) {
  if (min_length > min(picture_size.width, picture_size.height)) {
    return Result::UPLOAD_ANOTHER;
  }
  if (picture_size.width != picture_size.height) {
    return Result::CROP_IT;
  }
  return Result::ACCEPTED;
}
