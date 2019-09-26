#include "seating_arrangement.h"

unsigned getFacingSeatNumber(unsigned seat_number)
{
    const unsigned SEATS_IN_DOUBLE_COMPARTMENT = 12;

    seat_number--; // so seat number starts from 0

    unsigned relative_seat_number = seat_number % SEATS_IN_DOUBLE_COMPARTMENT;
    unsigned first_seat_number_in_double_compartment = seat_number - relative_seat_number;
    return first_seat_number_in_double_compartment + SEATS_IN_DOUBLE_COMPARTMENT - relative_seat_number;
}