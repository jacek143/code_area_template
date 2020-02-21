#include "almond_problem.h"

int almond_problem::compute_days_of_consumption(unsigned initial_amount,
                                                unsigned consumption_rate,
                                                unsigned restoration_rate) {
  if (initial_amount < consumption_rate) {
    return 0;
  }
  if (restoration_rate >= consumption_rate) {
    return -1;
  }
  return 1 + (initial_amount - consumption_rate) /
                 (consumption_rate - restoration_rate);
}
