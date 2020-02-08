#include "merge_sort.h"

using std::vector;

vector<int> merge_sorting::merge_sort(vector<int> to_sort) {
  if (to_sort.size() <= 1) {
    return to_sort;
  }
  vector<int> left(begin(to_sort), begin(to_sort) + to_sort.size() / 2);
  vector<int> right(begin(to_sort) + left.size(), end(to_sort));
  return merge(merge_sort(left), merge_sort(right));
}

vector<int> merge_sorting::merge(vector<int> left, vector<int> right) {
  vector<int> result = {};
  while (not left.empty() and not right.empty()) {
    if (left.at(0) <= right.at(0)) {
      result.push_back(left.at(0));
      left.erase(begin(left));
    } else {
      result.push_back(right.at(0));
      right.erase(begin(right));
    }
  }
  result.insert(end(result), begin(left), end(left));
  result.insert(end(result), begin(right), end(right));
  return result;
}
