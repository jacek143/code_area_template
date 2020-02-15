#include "vowel_game.h"
#include <algorithm>
#include <unordered_set>

using std::count_if;
using std::string;
using std::unordered_set;

unsigned vowel_game::count_vowels_in_all_substrings(const string &word) {
  unsigned total_vowels = 0;
  for (unsigned substr_size = 1; substr_size <= word.size(); substr_size++) {
    for (unsigned i = 0; i <= word.size() - substr_size; i++) {
      total_vowels += count_vowels(word.substr(i, substr_size));
    }
  }
  return total_vowels;
}

unsigned vowel_game::count_vowels(string word) {
  const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                   'A', 'E', 'I', 'O', 'U'};
  return count_if(begin(word), end(word), [&vowels](char character) {
    return vowels.find(character) != end(vowels);
  });
}
