#pragma once
#include <map>
#include <vector>

/**
 * @brief 
 *
 * @param n
 *
 * @return true if n is prime number
 */
bool is_prime(const int n);
/**
 * @brief 
 *
 * @param n
 *
 * @return all divisors of n
 */
std::vector<int> get_divisor(const int n);
/**
 * @brief find all prime numbers in [2, n]
 *
 * @param n
 *
 * @return all primes between 2 and n 
 */
std::vector<int> eratosthenes_sieve(const int n);
/**
 * @brief 
 *
 * @param n
 *
 * @return factors.
 */
std::map<int, int> get_prime_factor(int n);
