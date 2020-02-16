#include "vowel_game.h"
#include <unordered_set>

using std::string;
using std::unordered_set;

static bool is_vowel(char character) {
  const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                   'A', 'E', 'I', 'O', 'U'};
  return vowels.find(character) != end(vowels);
}

uint64_t vowel_game::count_vowels_in_all_substrings(const string &word) {
  uint64_t total_number_of_vowels = 0;
  uint64_t increase_of_vowels_caused_by_new_character = 0;
  for (uint64_t i = 0; i < word.size(); i++) {
    if (is_vowel(word[i])) {
      increase_of_vowels_caused_by_new_character += (i + 1);
    }
    total_number_of_vowels += increase_of_vowels_caused_by_new_character;
  }
  return total_number_of_vowels;
}
