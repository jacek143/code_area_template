#ifndef SEATING_ARRANGEMENT
#define SEATING_ARRANGEMENT

namespace seating_arrangement
{
enum class SeatType
{
    WINDOW,
    MIDDLE,
    AISLE
};
SeatType getSeatType(unsigned seat_number);
unsigned getFacingSeatNumber(unsigned seat_number);
} // namespace seating_arrangement

#endif
