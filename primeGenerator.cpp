// Prime Generator in C++
#include <iostream>
#include <vector>     // vector
#include <iterator>   // back_inserter
#include <algorithm>  // fill
#include <ctime>      // clock_t, clock
#include <cstring>    // memset
#include <cmath>      // sqrt
#include <cassert>    // assert

// typedefs
typedef int value_type;
typedef long long_value_type;
typedef std::vector<bool> sieve_table;


// Globals
const value_type UPPER_LIMIT = 1000000000;
const value_type SQRT_UPPER_LIMIT = static_cast<value_type> (sqrt(UPPER_LIMIT));
sieve_table smallPrimes (SQRT_UPPER_LIMIT + 1, true);

/**
 * Set up the initial cache of small primes
 * Uses the Sieve of Erotosthenes to fill the initial values
 */
void initSmallPrimes() {
    smallPrimes[0] = false;
    smallPrimes[1] = false;
    for (value_type i = 2; i <= SQRT_UPPER_LIMIT; ++i) {
        if (smallPrimes[i]) {
            for (int j = i * i; j <= SQRT_UPPER_LIMIT; j += i)
                smallPrimes[j] = false;
        }
    }
}

/**
 * Uses the Segmented Sieve of Ertosthenes algorithm to mark values as composite
 */
void getPrimesInRange(sieve_table& result, value_type begin, value_type end) {
    // Make sure we have enough room
    value_type lengthOfRange = end - begin + 1;
    result.resize(lengthOfRange, true);

    // Eliminate from target primes
    for (value_type k = 2; k <= SQRT_UPPER_LIMIT; ++k) {
        if (smallPrimes[k]) {
            // (x + y - 1) / y gets the ceiling of int division
            // i starts at ceil(begin / k) * k - a
            value_type i = (std::max(2, (begin + k - 1) / k)) * k - begin;

            for (; i < lengthOfRange; i += k)
                result[i] = false;
        }
    }
}

/**
 * Set the bounds of the range to be valid
 */
void setBoundsOnRange(value_type * range) {
    range[0] = std::max(range[0], static_cast<value_type> (2));
    range[1] = std::min(range[1], UPPER_LIMIT);
}

/**
 * Read the next line and store it as an array of ints
 */
void readRange(value_type * range) {
    std::cin >> range[0];
    std::cin >> range[1];
    setBoundsOnRange(range);
}

/**
 * @return true if n is a prime number
 *         false otherwise
 */
bool isPrime(sieve_table& table, value_type n) {
    return table[n];
}

/**
 * Read in the next line and print the primes the results
 */
void runCase() {
    value_type range[2];
    readRange(range);

    sieve_table mySieveTable;
    getPrimesInRange(mySieveTable, range[0], range[1]);

    value_type dist = range[1] - range[0];

    for (value_type i = 0; i <= dist; ++i) {
        if (mySieveTable[i])
            std::cout << i + range[0] << std::endl;
    }
}

int main() {
    // Fill eager cache
    double time_diff;
    clock_t start, end;
    start = clock();

    initSmallPrimes();

    int numberOfLines;
    std::cin >> numberOfLines;
    while (numberOfLines-- != 0) {
        runCase();

        // Print extra new line between test cases, but not after the last one
        if (numberOfLines != 0)
            std::cout << std::endl;
    }

    end = clock();
    time_diff = static_cast<double> (end - start) / CLOCKS_PER_SEC;
    std::cerr << "Time: " << time_diff << "\n" << std::flush;

    return 0;
}
