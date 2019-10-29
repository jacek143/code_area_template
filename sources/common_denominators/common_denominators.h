#ifndef COMMON_DENOMINATORS_H
#define COMMON_DENOMINATORS_H

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

namespace Fracts {
using Integer = unsigned long long;
using Rational = std::vector<Integer>;
using RationalsList = std::vector<Rational>;

Integer smallestCommonMultiple(Integer a, Integer b) {
  auto multiple = a * b;
  for (Integer i = 2; i <= std::min(a, b); i++) {
    while (a % i == 0 and b % i == 0) {
      multiple /= i;
      a /= i;
      b /= i;
    }
  }
  return multiple;
}

Integer smallestCommonDenominator(RationalsList rationals) {
  Integer denominator = 1;
  for (const auto &rational : rationals) {
    denominator = smallestCommonMultiple(denominator, rational[1]);
  }
  return denominator;
}

std::string listToString(const RationalsList &list) {
  std::stringstream stream;
  for (auto &&rational : list) {
    stream << "(" << rational.at(0) << "," << rational.at(1) << ")";
  }
  return stream.str();
}

Rational simplify(Rational number) {
  for (Integer i = 2; i <= number[1]; i++) {
    while (number[0] % i == 0 and number[1] % i == 0) {
      number[0] /= i;
      number[1] /= i;
    }
  }
  return number;
}

RationalsList simplify(RationalsList rationals) {
  RationalsList processed;
  while (rationals.size() > 0) {
    Rational number = simplify(rationals.back());
    rationals.pop_back();
    processed.insert(begin(processed), number);
  }
  return processed;
}

std::string convertFrac(RationalsList rationals) {
  rationals = simplify(rationals);
  auto denominator = smallestCommonDenominator(rationals);
  for (auto &r : rationals) {
    auto gain = denominator / r[1];
    r[0] *= gain;
    r[1] *= gain;
  }
  return listToString(rationals);
}
} // namespace Fracts

#endif
