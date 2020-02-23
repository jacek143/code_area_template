#include "urlify_in_place.h"

using urlify_in_place::buffer_t;

namespace {
struct Lengths {
  size_t current;
  size_t urlficated;
};

Lengths compute_lengths(const buffer_t *p_buffer) {
  Lengths lengths = {0, 0};
  for (size_t i = 0; p_buffer->at(i) != '\0'; i++) {
    lengths.current++;
    lengths.urlficated += p_buffer->at(i) == ' ' ? 3 : 1;
  }
  return lengths;
}

void urlify_knowing_lengths(buffer_t *p_buffer, Lengths lengths) {
  auto destination = lengths.urlficated;
  auto source = lengths.current;
  while (destination != source) {
    auto character = p_buffer->at(source--);
    if (character != ' ') {
      p_buffer->at(destination--) = character;
    } else {
      p_buffer->at(destination--) = '0';
      p_buffer->at(destination--) = '2';
      p_buffer->at(destination--) = '%';
    }
  }
}
} // namespace

void urlify_in_place::urlify(buffer_t *p_buffer) {
  urlify_knowing_lengths(p_buffer, compute_lengths(p_buffer));
}
