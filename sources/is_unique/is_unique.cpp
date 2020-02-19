#include "is_unique.h"

using std::make_pair;
using std::nullptr_t;
using std::pair;
using std::string;
using string_uniqueness::UniqueCharacterSet;

pair<nullptr_t, bool> UniqueCharacterSet::emplace(char character) {
  return make_pair(nullptr, try_insert(character));
}

bool UniqueCharacterSet::try_insert(char character) {
  bool insertion_successful = false;
  try {
    insert(character);
    insertion_successful = true;
  } catch (character_present &e) {
    ;
  }
  return insertion_successful;
}

void UniqueCharacterSet::insert(char character) {
  buffer.insert(find_place_to_insert(character), character);
}

string::iterator UniqueCharacterSet::find_place_to_insert(char character) {
  auto start = begin(buffer);
  auto stop = end(buffer);
  while (start != stop) {
    auto middle = start + (stop - start) / 2;
    if (character < *middle) {
      stop = middle;
    } else if (character > *middle) {
      start = middle + 1;
    } else {
      throw character_present();
    }
  }
  return start;
}
