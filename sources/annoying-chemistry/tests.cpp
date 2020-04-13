#include "annoying_chemistry.h"
#include "gtest/gtest.h"

using annoying_chemistry::input_parameters_t;
using annoying_chemistry::output_parameters_t;
using std::istringstream;
using std::ostringstream;

TEST(AnnoyingChemistryTests, checkIfCanReadParameters) {
  input_parameters_t parameters{};
  istringstream("2 14 9 1") >> parameters;

  EXPECT_EQ(parameters.x, 2);
  EXPECT_EQ(parameters.y, 14);
  EXPECT_EQ(parameters.p, 9);
  EXPECT_EQ(parameters.q, 1);
}

TEST(AnnoyingChemistryTests, checkIfCanSolveProblem) {
  input_parameters_t input = {2, 3, 4, 5};
  output_parameters_t output = solve(input);
  EXPECT_EQ(6, output.b1);
  EXPECT_EQ(5, output.b2);
  EXPECT_EQ(3, output.b3);
}

TEST(AnnoyingChemistryTests, checkIfCanPrintSolution) {
  ostringstream stream;
  stream << output_parameters_t{13, 21, 17};
  EXPECT_EQ("13 21 17", stream.str());
}
