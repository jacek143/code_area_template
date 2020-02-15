#ifndef VOWEL_GAME_H
#define VOWEL_GAME_H

#include <string>

namespace vowel_game {
unsigned count_vowels(std::string word);
unsigned count_vowels_in_all_substrings(const std::string &word);
} // namespace vowel_game

#endif
