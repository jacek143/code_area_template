#include "toggle_string.h"
#include <cctype>

using std::string;
using std::islower;
using std::tolower;
using std::toupper;

string toggle_string::toggleString(string input)
{
    for(auto&& c : input) {
        c = islower(c) ? toupper(c) : tolower(c);
    }
    return input;
}
