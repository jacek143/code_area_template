#include "find_product.h"

using std::vector;

uint64_t find_product::computeProductModulo(vector<uint64_t> array) {
  uint64_t product = 1;
  for (auto &&a : array) {
    product = product * a % 1000000007;
  }
  return product;
}
