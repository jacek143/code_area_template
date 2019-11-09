#include "matrix_determinant.h"

using matrix_determinant::int_t;
using matrix_determinant::matrix_t;

int_t matrix_determinant::determinant(matrix_t m) {
  if (m.size() == 1) {
    return m.at(0).at(0);
  }
  int_t det = 0;
  for (decltype(m.size()) i = 0; i < m.size(); i++) {
    int_t a_i = m.at(0).at(i);
    a_i *= i % 2 != 0 ? -1 : 1;
    det += a_i * determinant(minorForMatrix(i, m));
  }
  return det;
}

matrix_t matrix_determinant::minorForMatrix(int_t minor, matrix_t matrix) {
  matrix.erase(begin(matrix)); // remove row
  for (auto &&row : matrix) {
    row.erase(begin(row) + minor); // remove column
  }
  return matrix;
}
