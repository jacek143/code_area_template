#include "quadratic_integer_equation_solver.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using quadratic_intiger_equation::solution_t;
using quadratic_intiger_equation::solve_up_to;
using std::set;
using testing::ContainerEq;

TEST(CheckIfEquationSolver, worksForSmallestExample) {
  set<solution_t> expected{{1, 1, 1, 1}};
  EXPECT_THAT(solve_up_to(1), ContainerEq(expected));
}

TEST(CheckIfEquationSolver, worksForLimit2) {
  set<solution_t> expected{{1, 1, 1, 1}, {1, 2, 1, 2}, {1, 2, 2, 1},
                           {2, 1, 1, 2}, {2, 1, 2, 1}, {2, 2, 2, 2}};
  EXPECT_THAT(solve_up_to(2), ContainerEq(expected));
}
