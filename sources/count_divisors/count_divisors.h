#ifndef COUNT_DIVISORS_H
#define COUNT_DIVISORS_H

namespace count_divisors
{
struct InclusiveRange
{
    unsigned a;
    unsigned b;
};
unsigned countDivisibleInRange(unsigned divisor, InclusiveRange range);
} // namespace count_divisors

#endif
