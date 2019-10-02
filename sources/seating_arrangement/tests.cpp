#include "seating_arrangement.h"
#include "gtest/gtest.h"

using seating_arrangement::getFacingSeatNumber;
using seating_arrangement::getSeatType;
using seating_arrangement::SeatType;
using seating_arrangement::solveProblem;
using std::string;

class SeatingArrangement : public ::testing::Test {
public:
  void expectSeatsMapped(unsigned frontFacing, unsigned rearFacing) {
    EXPECT_EQ(getFacingSeatNumber(frontFacing), rearFacing);
    EXPECT_EQ(frontFacing, getFacingSeatNumber(rearFacing));
  }
};

TEST_F(SeatingArrangement, firstCompartment) {
  expectSeatsMapped(3, 10);
  expectSeatsMapped(2, 11);
  expectSeatsMapped(1, 12);
}

TEST_F(SeatingArrangement, secondCompartment) {
  expectSeatsMapped(6, 7);
  expectSeatsMapped(5, 8);
  expectSeatsMapped(4, 9);
}

TEST_F(SeatingArrangement, thirdCompartment) {
  expectSeatsMapped(15, 22);
  expectSeatsMapped(14, 23);
  expectSeatsMapped(13, 24);
}

TEST_F(SeatingArrangement, fourthCompartment) {
  expectSeatsMapped(18, 19);
  expectSeatsMapped(17, 20);
  expectSeatsMapped(16, 21);
}

TEST_F(SeatingArrangement, windowSeat) {
  EXPECT_EQ(SeatType::WINDOW, getSeatType(1));
  EXPECT_EQ(SeatType::WINDOW, getSeatType(6));
  EXPECT_EQ(SeatType::WINDOW, getSeatType(7));
  EXPECT_EQ(SeatType::WINDOW, getSeatType(12));
  EXPECT_EQ(SeatType::WINDOW, getSeatType(108));
}

TEST_F(SeatingArrangement, middleSeat) {
  EXPECT_EQ(SeatType::MIDDLE, getSeatType(2));
  EXPECT_EQ(SeatType::MIDDLE, getSeatType(5));
  EXPECT_EQ(SeatType::MIDDLE, getSeatType(107));
}

TEST_F(SeatingArrangement, aisleleSeat) {
  EXPECT_EQ(SeatType::AISLE, getSeatType(3));
  EXPECT_EQ(SeatType::AISLE, getSeatType(106));
}

TEST_F(SeatingArrangement, completeAnswer) {
  EXPECT_EQ("48 WS", solveProblem(37));
  EXPECT_EQ("58 AS", solveProblem(51));
  EXPECT_EQ("89 MS", solveProblem(92));
}
