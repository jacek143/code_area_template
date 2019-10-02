#ifndef LIFT_QUERIES_H
#define LIFT_QUERIES_H

#include <string>

namespace lift_queries {
class Lifts {
public:
  std::string queryForFloor(unsigned target_floor);

private:
  unsigned b_floor = 7;
  unsigned a_floor = 0;
};
std::string determineLift(unsigned target_floor);
} // namespace lift_queries

#endif
