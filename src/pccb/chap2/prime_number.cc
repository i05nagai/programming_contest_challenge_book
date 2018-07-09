#include "pccb/chap2/prime_number.h"

bool is_prime(const int n)
{
    // n = 1 is ignored
    for (int i = 2; i * i <= n; ++i) {
        // not prime number
        if (n % i == 0) {
            return false;
        }
    }
    // if n == 1, return false
    return n != 1;
}

// return all divisors
std::vector<int> get_divisor(const int n)
{
    std::vector<int> divisors(0);
    
    for (int i = 2; i * i <= n; ++i) {
        // divided 
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(static_cast<int>(n / i));
        }
    }

    return divisors;
}

std::vector<int> eratosthenes_sieve(const int n)
{
    bool isPrime[n + 1];
    std::vector<int> primes(0);

    //initiazlie
    std::fill(isPrime, isPrime + n + 1, true);

    // 0 and 1 is not prime
    int numPrime = 0;
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= n; ++i) {
        // i is not prime number
        if (isPrime[i]) {
            primes.push_back(i);
            // m * i (m >= 2) is not primes
            for (int j = 2 * i; j <= n; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    return primes;
}

std::map<int, int> get_prime_factor(int n)
{
    // factor number to number of occurrences
    std::map<int, int> numOccurrences;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++numOccurrences[i];
            n /= i;
        }
    }
    // if n is prime
    if (n != 1) {
        ++numOccurrences[n];
    }
    return numOccurrences;
}
