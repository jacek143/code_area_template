#include "pairs_with_same_difference.h"
#include <set>

using std::pair;
using std::set;
using std::vector;

vector<pair<int, int>>
pairs_with_same_difference::get_pairs_with_same_diff(vector<int> arr, int k) {
  vector<pair<int, int>> pairs;
  set<int> set(begin(arr), end(arr));
  for (auto &&x : set) {
    if (set.find(x + k) != end(set)) {
      pairs.emplace_back(x, x + k);
    }
  }
  return pairs;
}
