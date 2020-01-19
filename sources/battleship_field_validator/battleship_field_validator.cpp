#include "battleship_field_validator.h"
#include <algorithm>
#include <numeric>
#include <stdexcept>

using battleship_field_validator::BattlefiledValidator;

bool battleship_field_validator::validate_battlefield(
    const battlefield_t &battlefield) {
  BattlefiledValidator validator(battlefield);
  return validator.is_valid();
}

BattlefiledValidator::BattlefiledValidator(const battlefield_t &battlefield)
    : battlefield(battlefield) {
  ;
}

bool BattlefiledValidator::is_valid() const {
  return are_dimenstions_valid() and are_ships_separated_from_each_other() and
         is_total_length_of_ships_valid() and is_number_of_ships_correct();
}

bool BattlefiledValidator::are_dimenstions_valid() const {
  bool has_field_valid_number_of_rows = battlefield.size() == EXPECTED_SIZE;
  bool has_every_row_valid_length = std::all_of(
      begin(battlefield), end(battlefield),
      [this](const auto &row) { return row.size() == EXPECTED_SIZE; });
  return has_field_valid_number_of_rows and has_every_row_valid_length;
}

bool BattlefiledValidator::are_ships_separated_from_each_other() const {
  for (unsigned r = 0; r < EXPECTED_SIZE; r++) {
    for (unsigned c = 0; c < EXPECTED_SIZE; c++) {
      if (is_occupied(r, c)) {
        if (is_occupied(r + 1, c + 1) or is_occupied(r - 1, c + 1)) {
          return false;
        }
      }
    }
  }
  return true;
}

bool BattlefiledValidator::is_occupied(unsigned row, unsigned column) const {
  try {
    return battlefield.at(row).at(column) != 0;
  } catch (std::out_of_range &) {
    ;
  }
  return false;
}

bool BattlefiledValidator::is_total_length_of_ships_valid() const {
  return EXPECTED_TOTAL_LENGTH_OF_SHIPS ==
         std::accumulate(cbegin(battlefield), cend(battlefield), 0,
                         [](auto length, const auto &row) {
                           return length +
                                  std::accumulate(cbegin(row), cend(row), 0);
                         });
}

bool BattlefiledValidator::is_number_of_ships_correct() const {
  unsigned submarines = 0;
  unsigned destroyers = 0;
  unsigned cruises = 0;
  for (unsigned r = 0; r < EXPECTED_SIZE; r++) {
    for (unsigned c = 0; c < EXPECTED_SIZE; c++) {
      if (is_submarine(r, c)) {
        submarines++;
      } else if (is_destroyer(r, c)) {
        destroyers++;
      } else if (is_cruiser(r, c)) {
        cruises++;
      }
    }
  }
  return EXPECTED_SUBMARINES == submarines and
         EXPECTED_DESTROYERS == destroyers and EXPECTED_CRUISERS == cruises;
}

bool BattlefiledValidator::is_submarine(unsigned r, unsigned c) const {
  return get_length_of_ship_starting_at(r, c) == 1;
}

bool BattlefiledValidator::is_destroyer(unsigned r, unsigned c) const {
  return get_length_of_ship_starting_at(r, c) == 2;
}

bool BattlefiledValidator::is_cruiser(unsigned r, unsigned c) const {
  return get_length_of_ship_starting_at(r, c) == 3;
}

unsigned
BattlefiledValidator::get_length_of_ship_starting_at(unsigned r,
                                                     unsigned c) const {
  if (is_start_of_ship(r, c)) {
    return std::max(get_vertical_length_of_ship_starting_at(r, c),
                    get_horizontal_length_of_ship_starting_at(r, c));
  }
  return 0;
}

bool BattlefiledValidator::is_start_of_ship(unsigned r, unsigned c) const {
  return is_occupied(r, c) and not is_occupied(r, c - 1) and
         not is_occupied(r - 1, c);
}

unsigned BattlefiledValidator::get_vertical_length_of_ship_starting_at(
    unsigned r, unsigned c) const {
  unsigned length = 1;
  while (is_occupied(r + length, c)) {
    length++;
  }
  return length;
}

unsigned BattlefiledValidator::get_horizontal_length_of_ship_starting_at(
    unsigned r, unsigned c) const {
  unsigned length = 1;
  while (is_occupied(r, c + length)) {
    length++;
  }
  return length;
}
