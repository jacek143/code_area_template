#include "book_of_potion_making.h"

bool book_of_potion_making::validateIsbn(std::string isbn) {
  if (10 != isbn.size()) {
    return false;
  }
  unsigned sum = 0;
  for (unsigned i = 0; i < isbn.size(); i++) {
    sum += (i + 1) * isbn[i];
  }
  return sum % 11 == 0;
}
