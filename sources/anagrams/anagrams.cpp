#include "anagrams.h"
#include <algorithm>
#include <iostream>

using std::string;

unsigned anagrams::getNumberOfDeletionsToMakeAnagrams(string a, string b) {
  unsigned deletions = 0;
  while (a.size() > 0) {
    auto index_in_b = b.find(a.back());
    a.pop_back();
    if (index_in_b == string::npos) {
      deletions++;
    } else {
      b.erase(index_in_b, 1);
    }
  }
  deletions += b.size();
  return deletions;
}
