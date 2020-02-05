#include "sum_strings_as_numbers.h"

using std::max;
using std::string;
using std::to_string;

string remove_front_extra_zeros(string string);
string add_front(string string, unsigned char to_insert);

string sum_strings_as_numbers::sum_strings(string left_sumand,
                                           string right_sumand) {
  left_sumand = remove_front_extra_zeros(left_sumand);
  right_sumand = remove_front_extra_zeros(right_sumand);

  string sum_string;
  unsigned char carrier = 0;
  const auto n = max(left_sumand.size(), right_sumand.size());
  for (unsigned i = 0; i < n; i++) {
    if (right_sumand.size() - 1 >= i) {
      carrier += right_sumand.at(right_sumand.size() - 1 - i) - '0';
    }
    if (left_sumand.size() - 1 >= i) {
      carrier += left_sumand.at(left_sumand.size() - 1 - i) - '0';
    }
    sum_string = add_front(sum_string, carrier % 10);
    carrier /= 10;
  }
  if (carrier != 0) {
    sum_string = add_front(sum_string, carrier % 10);
  }
  return sum_string;
}

string remove_front_extra_zeros(string string) {
  while (*begin(string) == '0' and string.size() > 1) {
    string.erase(begin(string));
  }
  return string;
}

string add_front(string string, unsigned char to_insert) {
  string.insert(0, to_string(to_insert));
  return string;
}
