#include "ali_and_helping_innocent_people.h"
#include <vector>

using std::stoi;
using std::string;
using std::vector;

bool isLetterValid(const string &tag);
bool areDigitsValid(const string &tag);
vector<int> extract_digits(const string &tag);

bool ali_and_helping_innocent_people::isTagValid(const string &tag) {
  return isLetterValid(tag) and areDigitsValid(tag);
}

bool isLetterValid(const string &tag) {
  const string vowels = "AEIOUY";
  auto letter = tag.at(2);
  return vowels.find(letter) == string::npos;
}

bool areDigitsValid(const string &tag) {
  auto digits = extract_digits(tag);
  if ((digits.at(0) + digits.at(1)) % 2) {
    return false;
  }
  if ((digits.at(2) + digits.at(3)) % 2) {
    return false;
  }
  if ((digits.at(3) + digits.at(4)) % 2) {
    return false;
  }
  if ((digits.at(5) + digits.at(6)) % 2) {
    return false;
  }
  return true;
}

vector<int> extract_digits(const string &tag) {
  auto get_digit = [&tag](int index) { return stoi(tag.substr(index, 1)); };
  vector<int> digits;
  for (auto &&i : {0, 1, 3, 4, 5, 7, 8}) {
    digits.push_back(get_digit(i));
  }
  return digits;
}
