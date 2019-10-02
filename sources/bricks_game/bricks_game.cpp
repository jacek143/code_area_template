#include "bricks_game.h"

using std::string;

string bricks_game::determineWinner(unsigned number_of_bricks) {
  unsigned i = 0;
  while (3 * i < number_of_bricks) {
    number_of_bricks -= 3 * i;
    i++;
  }
  return i >= number_of_bricks ? "Patlu" : "Motu";
}
