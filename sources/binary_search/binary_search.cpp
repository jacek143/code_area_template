#include "binary_search.h"

using std::vector;

vector<int>::const_iterator
binary_searching::binary_search(const vector<int> &collection, int to_find) {
  auto begin = cbegin(collection);
  auto end = cend(collection);
  while (begin != end) {
    auto candidate = begin + (end - begin) / 2;
    if (*candidate == to_find) {
      return candidate;
    }
    if (*candidate > to_find) {
      end = candidate;
    } else {
      begin = candidate + 1;
    }
  }
  return cend(collection);
}
