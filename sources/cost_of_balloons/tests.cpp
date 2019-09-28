#include "gtest/gtest.h"
#include "cost_of_balloons.h"

using cost_of_balloons::UserStatus;
using std::vector;

TEST(CostOfBalloons, standardExample)
{
    unsigned green_balloon_price = 5;
    unsigned purple_balloon_price = 1;

    vector<UserStatus> statuses;
    // we pay 6 anyway
    statuses.push_back({true, true});
    // min(5+5+1, 1+1+5) = max(11, 7) = 7
    statuses.push_back({true, false});
    statuses.push_back({true, false});
    statuses.push_back({false, true});

    EXPECT_EQ(13, calculateMinTotalPrice(statuses, green_balloon_price, purple_balloon_price));
}
