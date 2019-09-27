#include "palindromic_string.h"
#include <algorithm>

using std::reverse;
using std::string;

bool isPalindrome(string potential_palindrome)
{
    auto reversed = potential_palindrome;
    reverse(begin(reversed), end(reversed));
    return reversed == potential_palindrome;
}
