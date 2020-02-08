#include "quicksort.h"

using std::vector;

void quicksorting::quicksort(vector<int> &to_sort) {
  if (to_sort.size() <= 1) {
    return;
  }
  int pivot = *begin(to_sort);
  vector<int> low, high;
  for (auto it = begin(to_sort) + 1; it != end(to_sort); it++) {
    if (*it < pivot) {
      low.push_back(*it);
    } else {
      high.push_back(*it);
    }
  }
  quicksort(low);
  quicksort(high);
  to_sort.clear();
  to_sort.insert(end(to_sort), begin(low), end(low));
  to_sort.push_back(pivot);
  to_sort.insert(end(to_sort), begin(high), end(high));
}
