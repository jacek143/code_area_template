#ifndef QUADRATIC_INTEGER_EQUATION_SOLVER_H
#define QUADRATIC_INTEGER_EQUATION_SOLVER_H

#include <set>
#include <tuple>

namespace quadratic_intiger_equation {
using solution_t = std::tuple<int, int, int, int>;

std::set<solution_t> solve_up_to(int limit);
} // namespace quadratic_intiger_equation

#endif
