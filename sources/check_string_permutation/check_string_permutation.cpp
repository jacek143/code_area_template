#include "check_string_permutation.h"
#include <unordered_set>

using std::string;
using std::unordered_multiset;

bool check_string_permutation::are_permutations(const string &first,
                                                const string &second) {
  return unordered_multiset<char>(begin(first), end(first)) ==
         unordered_multiset<char>(begin(second), end(second));
}
