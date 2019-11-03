#include "range_extraction.h"
#include <sstream>

void range_extraction::remove_last_comma(std::string &str) {
  if (not str.empty()) {
    str.pop_back();
  }
}

void range_extraction::format_ranges(std::string &str) {
  for (auto pos = str.find(",_"); pos != std::string::npos;
       pos = str.find(",_")) {
    str.replace(pos, 2, "-");
  }
  for (auto pos = str.find('_'); pos != std::string::npos;
       pos = str.find('_')) {
    str.erase(pos, 1);
  }
}

std::string range_extraction::range_extraction(std::vector<int> args) {
  std::stringstream stream;
  auto N = args.size();
  for (decltype(N) i = 0; i < N; i++) {
    bool in_range = false;
    if (i > 0 and i < N - 1) {
      if (args.at(i - 1) + 1 == args.at(i) and
          args.at(i) + 1 == args.at(i + 1)) {
        in_range = true;
      }
    }
    if (in_range) {
      stream << "_";
    } else {
      stream << args.at(i) << ",";
    }
  }
  auto str = stream.str();
  remove_last_comma(str);
  format_ranges(str);
  return str;
}
