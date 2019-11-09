#include "matrix_determinant.h"
#include "gtest/gtest.h"

using matrix_determinant::determinant;
using matrix_determinant::matrix_t;
using matrix_determinant::minorForMatrix;

TEST(MatrixDeterminant, isCalculatedForOneElementMatrix) {
  EXPECT_EQ(13, determinant({{13}}));
}

TEST(MatrixDeterminant, isCalculatedForMatrixOfSize2) {
  EXPECT_EQ(-1, determinant({{1, 3}, {2, 5}}));
}

TEST(MatrixDeterminant, isCalculatedForMatrixOfSize3) {
  EXPECT_EQ(-20, determinant({{2, 5, 3}, {1, -2, -1}, {1, 3, 4}}));
}

TEST(MinorMatrix, isCalculatedForMatrixOfSize2) {
  matrix_t matrix = {{0, 1}, {2, 3}};
  matrix_t minor_matrix_0 = minorForMatrix(0, matrix);
  matrix_t minor_matrix_1 = minorForMatrix(1, matrix);
  EXPECT_EQ(1, minor_matrix_0.size());
  EXPECT_EQ(1, minor_matrix_1.size());
  EXPECT_EQ(3, minor_matrix_0.at(0).at(0));
  EXPECT_EQ(2, minor_matrix_1.at(0).at(0));
}

TEST(MinorMatrix, isCalculatedForMatrixOfSize3) {
  matrix_t minor_matrix = minorForMatrix(1, {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});
  EXPECT_EQ(minor_matrix.size(), 2);
  EXPECT_EQ(3, minor_matrix.at(0).at(0));
  EXPECT_EQ(5, minor_matrix.at(0).at(1));
  EXPECT_EQ(6, minor_matrix.at(1).at(0));
  EXPECT_EQ(8, minor_matrix.at(1).at(1));
}
