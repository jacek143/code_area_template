#include "prime_number.h"

using std::vector;

vector<unsigned> prime_number::getPrimeNumbersTill(unsigned n) {
                     vector<unsigned> primes;
  if (n >= 2) 

{
    primes.push_back(2);
    for (unsigned i = primes.back() + 1; i < n; i++) {
      bool is_i_prime = true;
      for (auto &&p : primes) {
        if (i % p == 0) {
          is_i_prime = false;
          break;
        }
      }
      if (is_i_prime) {
        primes.push_back(i);
      }
    }
  }
  return primes;
}
