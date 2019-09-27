#include "find_product.h"

using std::vector;

unsigned long long find_product::computeProductModulo(vector<unsigned long long> array)
{
    unsigned long long product = 1;
    for (auto &&a : array)
    {
        product = product * a % 1000000007;
    }
    return product;
}
