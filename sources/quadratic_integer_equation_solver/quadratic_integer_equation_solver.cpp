#include "quadratic_integer_equation_solver.h"
#include <unordered_map>
#include <vector>

using quadratic_intiger_equation::solution_t;
using std::set;
using std::tuple;
using std::unordered_map;
using std::vector;

set<solution_t> quadratic_intiger_equation::solve_up_to(int limit) {
  unordered_map<int, vector<tuple<int, int>>> sums_to_pairs;
  for (int i = 1; i <= limit; i++) {
    for (int j = 1; j <= limit; j++) {
      int sum = i * i + j * j;
      if (sums_to_pairs.find(sum) == end(sums_to_pairs)) {
        sums_to_pairs.emplace(sum, vector<tuple<int, int>>());
      }
      sums_to_pairs.at(sum).emplace_back(i, j);
    }
  }
  set<solution_t> solutions;
  for (auto it = begin(sums_to_pairs); it != end(sums_to_pairs); it++) {
    auto &pairs = it->second;
    for (auto left = begin(pairs); left != end(pairs); left++) {
      for (auto right = begin(pairs); right != end(pairs); right++) {
        solutions.emplace(tuple_cat(*left, *right));
      }
    }
  }
  return solutions;
}
