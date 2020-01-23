#include "multiplying_numbers_as_strings.h"

using std::max;
using std::string;
using std::to_string;
using string_math::add;

static string multiply_longer_by_shorter(const string &longer,
                                         const string &shorter);
static string multiply_by_single_digit(const string &number, char single_digit);
static string strip_leading_zeros(string number);
static string multiply_by_power_of_ten(const string &number, unsigned n);
static int char_to_int(char single_digit);

string string_math::multiply(const string &a, const string &b) {
  return a.size() > b.size() ? multiply_longer_by_shorter(a, b)
                             : multiply_longer_by_shorter(b, a);
}

string string_math::add(string a, string b) {
  unsigned max_size = max(a.size(), b.size());
  a = string(max_size - a.size(), '0') + a;
  b = string(max_size - b.size(), '0') + b;
  string result;
  int buffer = 0;
  for (unsigned i = 1; i <= max_size; i++) {
    buffer += char_to_int(a.at(max_size - i)) + char_to_int(b.at(max_size - i));
    result.insert(0, to_string(buffer % 10));
    buffer /= 10;
  }
  if (buffer > 0) {
    result.insert(0, to_string(buffer));
  }
  return result;
}

string multiply_longer_by_shorter(const string &longer, const string &shorter) {
  string result = "0";
  for (unsigned i = 0; i < shorter.size(); i++) {
    char digit = shorter.at(shorter.size() - i - 1);
    string subresult =
        multiply_by_power_of_ten(multiply_by_single_digit(longer, digit), i);
    result = add(result, subresult);
  }
  return result;
}

string multiply_by_power_of_ten(const string &number, unsigned n) {
  return number + string(n, '0');
}

string multiply_by_single_digit(const string &number, char single_digit) {
  int right_factor = char_to_int(single_digit);
  string result;
  int buffer = 0;
  for (auto it = rbegin(number); it != rend(number); it++) {
    int left_factor = char_to_int(*it);
    buffer += left_factor * right_factor;
    result.insert(0, to_string(buffer % 10));
    buffer /= 10;
  }
  if (buffer > 0) {
    result.insert(0, to_string(buffer));
  }

  result = strip_leading_zeros(result);

  return result;
}

string strip_leading_zeros(string number) {
  while (number.at(0) == '0' and number.size() > 1) {
    number.erase(begin(number));
  }
  return number;
}

int char_to_int(char single_digit) { return single_digit - '0'; }
