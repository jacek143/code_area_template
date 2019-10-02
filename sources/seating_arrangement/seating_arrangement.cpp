#include "seating_arrangement.h"

using seating_arrangement::SeatType;
using std::string;
using std::to_string;

string seating_arrangement::solveProblem(unsigned seat_number) {
  string answer = to_string(getFacingSeatNumber(seat_number)) + " ";
  SeatType seat_type = getSeatType(seat_number);
  if (seat_type == SeatType::AISLE) {
    answer += "AS";
  } else if (seat_type == SeatType::MIDDLE) {
    answer += "MS";
  } else {
    answer += "WS";
  }
  return answer;
}

unsigned seating_arrangement::getFacingSeatNumber(unsigned seat_number) {
  const unsigned SEATS_IN_DOUBLE_COMPARTMENT = 12;

  unsigned relative_seat_number =
      ((seat_number - 1) % SEATS_IN_DOUBLE_COMPARTMENT) + 1;
  unsigned first_seat_number_in_double_compartment =
      seat_number - relative_seat_number + 1;
  return first_seat_number_in_double_compartment + SEATS_IN_DOUBLE_COMPARTMENT -
         relative_seat_number;
}

SeatType seating_arrangement::getSeatType(unsigned seat_number) {
  if ((seat_number + 1) % 3 == 0) {
    return SeatType::MIDDLE;
  }
  if ((seat_number - 1) % 6 == 0 or seat_number % 6 == 0) {
    return SeatType::WINDOW;
  }
  return SeatType::AISLE;
}
