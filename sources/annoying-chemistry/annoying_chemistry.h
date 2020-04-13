#ifndef ANNOYING_CHEMISTRY_H
#define ANNOYING_CHEMISTRY_H

#include <cstdint>
#include <istream>
#include <ostream>

namespace annoying_chemistry {

struct input_parameters_t {
  uint64_t x;
  uint64_t y;
  uint64_t p;
  uint64_t q;
};

struct output_parameters_t {
  uint64_t b1;
  uint64_t b2;
  uint64_t b3;
};

std::istream &operator>>(std::istream &stream, input_parameters_t &parameters);
std::ostream &operator<<(std::ostream &stream,
                         const output_parameters_t &parameters);
output_parameters_t solve(input_parameters_t input);

} // namespace annoying_chemistry

#endif
