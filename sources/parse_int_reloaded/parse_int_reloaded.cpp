#include "parse_int_reloaded.h"
#include <map>
#include <sstream>

using std::map;
using std::move;
using std::string;
using std::stringstream;

static string remove_dash(string number_string) {
  for (auto pos = number_string.find('-'); pos != string::npos;
       pos = number_string.find('-')) {
    number_string.replace(pos, 1, " ");
  }
  return number_string;
}

static int64_t word_to_int(const string &single_number_word) {
  map<string, int64_t> parse_dict = {
      {"zero", 0},     {"one", 1},        {"two", 2},       {"three", 3},
      {"four", 4},     {"five", 5},       {"six", 6},       {"seven", 7},
      {"eight", 8},    {"nine", 9},       {"ten", 10},      {"eleven", 11},
      {"twelve", 12},  {"thirteen", 13},  {"fourteen", 14}, {"fifteen", 15},
      {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
      {"twenty", 20},  {"thirty", 30},    {"forty", 40},    {"fifty", 50},
      {"sixty", 60},   {"seventy", 70},   {"eighty", 80},   {"ninety", 90}};
  auto itr = parse_dict.find(single_number_word);
  return itr != parse_dict.end() ? itr->second : 0;
}

int64_t parse_int_reloaded::parse_int(string number_string) {
  stringstream stream(remove_dash(move(number_string)));
  int64_t integer = 0;
  while (stream.good()) {
    string single_word;
    stream >> single_word;
    if (single_word == "million") {
      integer *= 1000000;
    }
    if (single_word == "thousand") {
      integer += (integer % 1000000) * 999;
    } else if (single_word == "hundred") {
      integer += (integer % 1000) * 99;
    } else {
      integer += word_to_int(single_word);
    }
  }
  return integer;
}
