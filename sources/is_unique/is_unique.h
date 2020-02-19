#ifndef IS_UNIQUE_H
#define IS_UNIQUE_H

#include <string>

namespace string_uniqueness {
template <class ContainerType> bool is_unique(const std::string &string) {
  ContainerType encountered_characters;
  for (auto &&character : string) {
    if (not encountered_characters.emplace(character).second) {
      return false;
    }
  }
  return true;
}

class UniqueCharacterSet {
public:
  std::pair<std::nullptr_t, bool> emplace(char character);

private:
  class character_present : std::exception {};
  bool try_insert(char character);
  void insert(char character);
  std::string::iterator find_place_to_insert(char character);

  std::string buffer;
};

} // namespace string_uniqueness

#endif
