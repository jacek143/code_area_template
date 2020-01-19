#include "battleship_field_validator.h"
#include "gtest/gtest.h"

using battleship_field_validator::battlefield_t;
using battleship_field_validator::validate_battlefield;

class CheckIfBattlefieldValidation : public testing::Test {
public:
  battlefield_t battlefield;
  void EXPECT_VALIDATION_RESULT(bool expected) {
    EXPECT_EQ(expected, validate_battlefield(battlefield));
  }
};

TEST_F(CheckIfBattlefieldValidation, acceptsValidBattlefield) {
  battlefield = {
      {1, 1, 1, 1, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
      {1, 1, 1, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      {1, 0, 1, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  EXPECT_VALIDATION_RESULT(true);
}

TEST_F(CheckIfBattlefieldValidation, rejectsNonSquaresFields) {
  battlefield = {
      {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 0, 1, 0, 1, 0, 1, 0, 0},    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  EXPECT_VALIDATION_RESULT(false);
}

TEST_F(CheckIfBattlefieldValidation, rejectsFieldWithSizeDifferentThan10) {
  battlefield = {{1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {1, 1, 1, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {1, 1, 0, 1, 1, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {1, 0, 1, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  EXPECT_VALIDATION_RESULT(false);
}

TEST_F(CheckIfBattlefieldValidation, rejectsShipsConnectedBackslash) {
  battlefield = {{1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, // diagonal connection
                 {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {1, 1, 0, 1, 1, 0, 1, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  EXPECT_VALIDATION_RESULT(false);
}

TEST_F(CheckIfBattlefieldValidation, rejectsShipsConnectedBySlash) {
  battlefield = {{1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}, // diagonal connection
                 {1, 1, 1, 0, 1, 1, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  EXPECT_VALIDATION_RESULT(false);
}

TEST_F(CheckIfBattlefieldValidation, rejectsIfTotalLengthOfShipsIsIncorrect) {
  battlefield = {{1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, // too long battleship
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 1, 1, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 1, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  EXPECT_VALIDATION_RESULT(false);
}

TEST_F(CheckIfBattlefieldValidation,
       rejectsFieldWithIncorrectNumberOfSubmarines) {
  battlefield = {
      {1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 0, 1, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  EXPECT_VALIDATION_RESULT(false);
}

TEST_F(CheckIfBattlefieldValidation,
       rejectsFieldWithIncorrectNumberOfDestroyers) {
  battlefield = {
      {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      {1, 0, 1, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  EXPECT_VALIDATION_RESULT(false);
}

TEST_F(CheckIfBattlefieldValidation, rejectsFieldWithIncorrectNumberOfCruises) {
  battlefield = {
      {1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      {1, 0, 1, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  EXPECT_VALIDATION_RESULT(false);
}
