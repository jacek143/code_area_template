#include "split_houses.h"

using std::string;

string split_houses::splitHouses(string house_placement) {
  if (string::npos != house_placement.find("HH")) {
    house_placement = "";
  } else {
    for (auto &&c : house_placement) {
      if (c == '.') {
        c = 'B';
      }
    }
  }
  return house_placement;
}
