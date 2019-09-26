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

TEST_F(SeatingArrangement, thirdCompartment)
{
    expectSeatsMapped(15, 22);
    expectSeatsMapped(14, 23);
    expectSeatsMapped(13, 24);
}

TEST_F(SeatingArrangement, fourthCompartment)
{
    expectSeatsMapped(18, 19);
    expectSeatsMapped(17, 20);
    expectSeatsMapped(16, 21);
}