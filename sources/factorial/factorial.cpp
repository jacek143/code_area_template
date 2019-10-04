#include "factorial.h"

unsigned factorial::computeFactorial(unsigned n) {
  unsigned result = 1;
  for (unsigned i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}
