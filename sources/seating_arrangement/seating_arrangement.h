#ifndef SEATING_ARRANGEMENT
#define SEATING_ARRANGEMENT

#include <string>

namespace seating_arrangement {
std::string solveProblem(unsigned seat_number);
enum class SeatType { WINDOW, MIDDLE, AISLE };
SeatType getSeatType(unsigned seat_number);
unsigned getFacingSeatNumber(unsigned seat_number);
} // namespace seating_arrangement

#endif
