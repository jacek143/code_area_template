#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

namespace binary_searching {
std::vector<int>::const_iterator
binary_search(const std::vector<int> &collection, int to_find);
}

#endif
