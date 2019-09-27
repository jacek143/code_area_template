#include "factorial.h"

unsigned factorial(unsigned n)
{
    unsigned result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}
