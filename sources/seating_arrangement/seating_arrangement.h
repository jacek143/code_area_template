#ifndef SEATING_ARRANGEMENT
#define SEATING_ARRANGEMENT

enum class SeatType
{
    WINDOW,
    MIDDLE,
    AISLE
};

unsigned getFacingSeatNumber(unsigned seat_number);
SeatType getSeatType(unsigned seat_number);

#endif
