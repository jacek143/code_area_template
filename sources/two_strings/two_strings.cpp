#include "two_strings.h"
#include <algorithm>

using std::sort;
using std::string;

bool two_strings::areEqual(string a, string b) {
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  return a == b;
}
