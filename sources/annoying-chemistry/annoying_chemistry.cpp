#include "annoying_chemistry.h"
#include <algorithm>
#include <sstream>

using std::istream;
using std::istringstream;
using std::ostream;
using std::ostringstream;

namespace annoying_chemistry {

istream &operator>>(istream &stream, input_parameters_t &parameters) {
  stream >> parameters.x;
  stream >> parameters.y;
  stream >> parameters.p;
  stream >> parameters.q;
  return stream;
}

ostream &operator<<(ostream &stream, const output_parameters_t &parameters) {
  stream << parameters.b1 << " " << parameters.b2 << " " << parameters.b3;
  return stream;
}

output_parameters_t solve(input_parameters_t input) {
  uint64_t b3;
  for (b3 = 1;
       ((b3 * input.p) % input.x) != 0 or ((b3 * input.q) % input.y) != 0;
       b3++) {
    ;
  }
  return {(b3 * input.p) / input.x, (b3 * input.q) / input.y, b3};
}

} // namespace annoying_chemistry
