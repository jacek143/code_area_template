#include "friends_relationship.h"
#include <sstream>

using std::endl;
using std::string;
using std::stringstream;

string friends_relationship::generatePatter(unsigned seed) {
  stringstream pattern;
  for (unsigned i = 1; i <= seed; i++) {
    pattern << string(i, '*') << string(2 * (seed - i), '#') << string(i, '*')
            << endl;
  }
  return pattern.str();
}
