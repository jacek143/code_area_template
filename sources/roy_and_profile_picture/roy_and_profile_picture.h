#ifndef ROY_AND_PROFILE_PICTURE_H
#define ROY_AND_PROFILE_PICTURE_H

namespace roy_and_profile_picture
{
struct PictureSize
{
    unsigned width;
    unsigned height;
};
enum class Result
{
    UPLOAD_ANOTHER,
    ACCEPTED,
    CROP_IT
};
Result checkPicture(unsigned min_length, PictureSize picture_size);
} // namespace roy_and_profile_picture

#endif
