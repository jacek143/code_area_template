#ifndef MATRIX_DETERMINANT_H
#define MATRIX_DETERMINANT_H

#include <vector>

namespace matrix_determinant {
using int_t = long long;
using matrix_t = std::vector<std::vector<int_t>>;
matrix_t minorForMatrix(int_t minor, matrix_t matrix);
int_t determinant(matrix_t m);
} // namespace matrix_determinant

#endif
