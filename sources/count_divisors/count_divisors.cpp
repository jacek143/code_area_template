#include "count_divisors.h"
#include <algorithm>

using std::max;
using std::min;

unsigned count_divisors::countDivisibleInRange(unsigned divisor,
                                               InclusiveRange range) {
  unsigned count = 0;
  for (unsigned i = min(range.a, range.b); i <= max(range.a, range.b); i++) {
    if (i % divisor == 0) {
      count++;
    }
  }
  return count;
}
