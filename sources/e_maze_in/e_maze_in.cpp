#include "e_maze_in.h"

using std::string;
using std::to_string;

string e_maze_in::determineCurrentPosition(string commands) {
  auto x = 0;
  auto y = 0;
  for (auto &&c : commands) {
    if (c == 'L') {
      x--;
    } else if (c == 'R') {
      x++;
    } else if (c == 'U') {
      y++;
    } else if (c == 'D') {
      y--;
    }
  }
  return to_string(x) + " " + to_string(y);
}
