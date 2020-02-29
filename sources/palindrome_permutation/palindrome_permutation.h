#ifndef PALINDROME_PERMUTATION_H
#define PALINDROME_PERMUTATION_H

#include <string>
#include <unordered_map>
#include <unordered_set>

namespace palindrome_permutation {

using chars_count_t = std::unordered_map<char, unsigned>;
using unique_strings_t = std::unordered_set<std::string>;

unique_strings_t find_palindromic_permutations(const std::string &input);
chars_count_t count_characters(const std::string &string);
unique_strings_t generate_permutations(const std::string &input);

} // namespace palindrome_permutation

#endif
