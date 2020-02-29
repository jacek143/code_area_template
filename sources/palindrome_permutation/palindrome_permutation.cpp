#include "palindrome_permutation.h"
#include <algorithm>

using std::reverse;
using std::string;
using std::transform;

namespace palindrome_permutation {

struct AnalysisResult {
  string static_core;
  string permutable_part;
};

static string get_lowercase(string string);
static AnalysisResult
analyse_character_count(const chars_count_t &characters_count);
static unique_strings_t
generate_palindromes_from_analysis(const AnalysisResult &analysis);
static string get_reverse(string string);

unique_strings_t find_palindromic_permutations(const string &input) {
  auto lower_case = get_lowercase(input);
  auto characters_count = count_characters(lower_case);
  auto analysis = analyse_character_count(characters_count);
  return generate_palindromes_from_analysis(analysis);
}

string get_lowercase(string string) {
  transform(begin(string), end(string), begin(string), tolower);
  return string;
}

chars_count_t count_characters(const string &string) {
  chars_count_t characters_count;
  for (char c : string) {
    auto it = characters_count.find(c);
    if (it != end(characters_count)) {
      (it->second)++;
    } else {
      characters_count[c] = 1;
    }
  }
  return characters_count;
}

AnalysisResult analyse_character_count(const chars_count_t &characters_count) {
  AnalysisResult result = {"", ""};
  for (auto &&pair : characters_count) {
    char character = pair.first;
    auto count = pair.second;
    if (count % 2 == 0) {
      result.permutable_part += string(count / 2, character);
    } else if (result.static_core.empty()) {
      result.static_core += character;
    } else {
      return {}; // cannot be a palindrome
    }
  }
  return result;
}

unique_strings_t
generate_palindromes_from_analysis(const AnalysisResult &analysis) {
  if (analysis.permutable_part.empty() and analysis.static_core.empty()) {
    return {};
  }

  if (analysis.permutable_part.empty()) {
    return {analysis.static_core};
  }

  unique_strings_t output;
  for (auto &&permutation : generate_permutations(analysis.permutable_part)) {
    output.insert(permutation + analysis.static_core +
                  get_reverse(permutation));
  }
  return output;
}

unique_strings_t generate_permutations(const string &input) {
  if (input.size() == 1) {
    return {input};
  }
  unique_strings_t permutations;
  for (size_t i = 0; i < input.size(); i++) {
    char c = input.at(i);
    for (auto &&subpermutation :
         generate_permutations(input.substr(0, i) + input.substr(i + 1))) {
      permutations.emplace(c + subpermutation);
    }
  }
  return permutations;
}

string get_reverse(string string) {
  reverse(begin(string), end(string));
  return string;
}

} // namespace palindrome_permutation
