#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

namespace merge_sorting {
std::vector<int> merge_sort(std::vector<int> to_sort);
std::vector<int> merge(std::vector<int> left, std::vector<int> right);
} // namespace merge_sorting

#endif
