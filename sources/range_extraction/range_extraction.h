#ifndef RANGE_EXTRACTION_H
#define RANGE_EXTRACTION_H

#include <string>
#include <vector>

namespace range_extraction {
std::string range_extraction(std::vector<int> args);
void remove_last_comma(std::string &str);
void format_ranges(std::string &str);
} // namespace range_extraction

#endif
