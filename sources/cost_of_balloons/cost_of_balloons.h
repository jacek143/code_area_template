#ifndef COST_OF_BALLOONS_H
#define COST_OF_BALLOONS_H

#include <vector>

namespace cost_of_balloons {
struct UserStatus {
  bool first_solved;
  bool second_solved;
};
unsigned calculateMinTotalPrice(std::vector<UserStatus> statuses,
                                unsigned green_balloon_price,
                                unsigned purple_balloon_price);
} // namespace cost_of_balloons

#endif
