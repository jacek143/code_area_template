#ifndef URLIFY_IN_PLACE_H
#define URLIFY_IN_PLACE_H

#include <array>

namespace urlify_in_place {
using buffer_t = std::array<char, 100>;
void urlify(buffer_t *p_buffer);
} // namespace urlify_in_place

#endif
