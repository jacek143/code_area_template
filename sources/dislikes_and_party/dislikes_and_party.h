#ifndef DISLIKES_AND_PARTY_H
#define DISLIKES_AND_PARTY_H

#include <istream>
#include <vector>

using dislike_matrix_t = std::vector<std::vector<uint64_t>>;

uint64_t count_impossible_handshakes(const dislike_matrix_t &dislike_matrix);
dislike_matrix_t read_dislike_matrix(std::istream &input);
uint64_t read_friends(std::istream &input);
uint64_t count_handshakes(uint64_t friends,
                          const dislike_matrix_t &dislike_matrix);
uint64_t count_handshakes(std::istream &input);

#endif
