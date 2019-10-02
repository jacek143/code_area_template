#include "lift_queries.h"
#include <cmath>

using lift_queries::Lifts;
using std::max;
using std::min;
using std::string;

string Lifts::queryForFloor(unsigned target_floor) {

  auto b_diff = max(target_floor, b_floor) - min(target_floor, b_floor);
  auto a_diff = max(target_floor, a_floor) - min(target_floor, a_floor);
  string retval;
  if (a_diff <= b_diff) {
    a_floor = target_floor;
    retval = "A";
  } else {
    b_floor = target_floor;
    retval = "B";
  }
  return retval;
}
