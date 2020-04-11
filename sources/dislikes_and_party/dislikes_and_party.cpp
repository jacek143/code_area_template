#include "dislikes_and_party.h"
#include <algorithm>
#include <set>

using std::istream;
using std::minmax;
using std::pair;
using std::set;

uint64_t read_number(istream &input);

uint64_t count_handshakes(istream &input) {
  auto friends = read_friends(input);
  auto dislike_matrix = read_dislike_matrix(input);
  return count_handshakes(friends, dislike_matrix);
}

uint64_t read_friends(istream &input) { return read_number(input); }

dislike_matrix_t read_dislike_matrix(istream &input) {
  const uint64_t DISLIKING = 10;
  const uint64_t DISLIKED_PER_DISLIKING = 10;

  dislike_matrix_t dislike_matrix;
  for (uint64_t i = 0; i < DISLIKING; i++) {
    dislike_matrix.push_back({});
    for (uint64_t j = 0; j < DISLIKED_PER_DISLIKING; j++) {
      dislike_matrix.back().push_back(read_number(input));
    }
  }
  return dislike_matrix;
}

uint64_t count_handshakes(uint64_t friends,
                          const dislike_matrix_t &dislike_matrix) {
  uint64_t pairs = (friends * (friends - 1)) / 2;
  return pairs - count_impossible_handshakes(dislike_matrix);
}

uint64_t count_impossible_handshakes(const dislike_matrix_t &dislike_matrix) {
  set<pair<uint64_t, uint64_t>> impossible_handshakes;
  for (const auto &row : dislike_matrix) {
    uint64_t disliking = *begin(row);
    for (auto itrDisliked = begin(row) + 1; itrDisliked != end(row);
         itrDisliked++) {
      impossible_handshakes.emplace(minmax(disliking, *itrDisliked));
    }
  }
  return impossible_handshakes.size();
}

uint64_t read_number(istream &input) {
  uint64_t n;
  input >> n;
  return n;
}
