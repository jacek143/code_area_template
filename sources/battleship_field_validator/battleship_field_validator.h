#ifndef BATTLESHIP_FIELD_VALIDATOR_H
#define BATTLESHIP_FIELD_VALIDATOR_H

#include <vector>

namespace battleship_field_validator {
using battlefield_t = std::vector<std::vector<int>>;

class BattlefiledValidator {
public:
  BattlefiledValidator(const battlefield_t &battlefield);
  bool is_valid() const;

private:
  bool are_dimenstions_valid() const;
  bool are_ships_separated_from_each_other() const;
  bool is_total_length_of_ships_valid() const;
  bool is_number_of_ships_correct() const;

  bool is_submarine(unsigned r, unsigned c) const;
  bool is_destroyer(unsigned r, unsigned c) const;
  bool is_cruiser(unsigned r, unsigned c) const;

  unsigned get_length_of_ship_starting_at(unsigned r, unsigned c) const;
  unsigned get_vertical_length_of_ship_starting_at(unsigned r,
                                                   unsigned c) const;
  unsigned get_horizontal_length_of_ship_starting_at(unsigned r,
                                                     unsigned c) const;

  bool is_start_of_ship(unsigned r, unsigned c) const;
  bool is_occupied(unsigned row, unsigned column) const;

  const int EXPECTED_TOTAL_LENGTH_OF_SHIPS = 20;
  const unsigned EXPECTED_SIZE = 10;
  const unsigned EXPECTED_SUBMARINES = 4;
  const unsigned EXPECTED_DESTROYERS = 3;
  const unsigned EXPECTED_CRUISERS = 2;
  const battlefield_t &battlefield;
};

bool validate_battlefield(const battlefield_t &battlefield);

} // namespace battleship_field_validator

#endif
