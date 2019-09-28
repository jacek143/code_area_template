#include "cost_of_balloons.h"
#include <algorithm>

using cost_of_balloons::UserStatus;
using std::count_if;
using std::max;
using std::min;
using std::vector;

unsigned cost_of_balloons::calculateMinTotalPrice(vector<UserStatus> statuses, unsigned green_balloon_price, unsigned purple_balloon_price)
{
    auto cheap_price = min(green_balloon_price, purple_balloon_price);
    auto expensive_price = max(green_balloon_price, purple_balloon_price);
    auto prizes_for_first = count_if(begin(statuses), end(statuses), [](auto status) { return status.first_solved; });
    auto prizes_for_second = count_if(begin(statuses), end(statuses), [](auto status) { return status.second_solved; });
    auto easier_count = max(prizes_for_first, prizes_for_second);
    auto harder_count = min(prizes_for_first, prizes_for_second);
    return easier_count * cheap_price + harder_count * expensive_price;
}
