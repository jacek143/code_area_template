#include "seating_arrangement.h"

unsigned getFacingSeatNumber(unsigned seat_number)
{
    const unsigned SEATS_IN_ROW = 6;
    return seat_number + 2 * (SEATS_IN_ROW - seat_number) + 1;
}