#include "gtest/gtest.h"
#include "seating_arrangement.h"

class SeatingArrangement : public ::testing::Test
{
public:
    void expectSeatsMapped(unsigned frontFacing, unsigned rearFacing)
    {
        EXPECT_EQ(getFacingSeatNumber(frontFacing), rearFacing);
        EXPECT_EQ(frontFacing, getFacingSeatNumber(rearFacing));
    }
};

TEST_F(SeatingArrangement, firstCompartment)
{
    expectSeatsMapped(3, 10);
    expectSeatsMapped(2, 11);
    expectSeatsMapped(1, 12);
}

TEST_F(SeatingArrangement, secondCompartment)
{
    expectSeatsMapped(6, 7);
    expectSeatsMapped(5, 8);
    expectSeatsMapped(4, 9);
}
