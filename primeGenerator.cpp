// Prime Generator in C++
#include <iostream>
#include <vector>   // vector
#include <cstring>  // memset
#include <cmath>    // sqrt
#include <cassert>  // assert

// typedefs
typedef int value_type;
typedef long long_value_type;

typedef std::vector<bool> sieve_table;
typedef std::vector<value_type> eager_cache_type;
typedef eager_cache_type::iterator eager_cache_type_iterator;

// Limits on input
const value_type UPPER_LIMIT = 1000000000;
const value_type SQRT_UPPER_LIMIT = ceil((sqrt(UPPER_LIMIT)));

// The eager cache
eager_cache_type global_eager_cache;

/**
 * Fill the eager cache when first running
 *
 * This will create a list of all prime numbers between 2
 * and UPPER_LIMIT
 *
 * There are too many prime numbers to include all values in the source as
 * a meta cache
 *
 * Uses the Sieve of Atkin algorithm
 */
void fillEagerCache() {
    // Initialize the sieve table
    sieve_table mySieveTable (UPPER_LIMIT + 1, false);

    // assert(false);

    mySieveTable[2] = true;
    mySieveTable[3] = true;

    for (value_type i = 1; i <= SQRT_UPPER_LIMIT; ++i) {
        for (value_type j = 1; j <= SQRT_UPPER_LIMIT; ++j) {
            long_value_type i_squared = i * i;
            long_value_type j_squared = j * j;
            long_value_type i_squared_3 = 3 * i_squared;

            long_value_type v1 = 4 * i_squared + j_squared;
            long_value_type v2 = i_squared_3 + j_squared;

            if ((v1 <= UPPER_LIMIT) && ((v1 % 12 == 1) || (v1 % 12 == 5)))
                mySieveTable[v1] = !mySieveTable[v1];

            if ((v2 <= UPPER_LIMIT) && (v2 % 12 == 7))
                mySieveTable[v2] = !mySieveTable[v2];

            if (i > j) {
                long_value_type v3 = i_squared_3 - j_squared;
                if ((v3 <= UPPER_LIMIT) && (v3 % 12 == 11)) {
                    mySieveTable[v3] = !mySieveTable[v3];
                }
            }
        }
    }

    // Sieve and eliminate composites
    for (value_type i = 5; i <= SQRT_UPPER_LIMIT; ++i) {
        if (mySieveTable[i]) {
            value_type i_squared = i * i;
            for (value_type k = i_squared; k <= UPPER_LIMIT; k += i_squared) {
                mySieveTable[k] = false;
            }
        }
    }

    // Print all values to the cache
    for (int i = 2; i <= UPPER_LIMIT; ++i) {
        if (mySieveTable[i])
            global_eager_cache.push_back(i);
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
 * Read in the next line and print the primes the results
 */
void runCase() {
    value_type range[2];
    readRange(range);

    eager_cache_type_iterator i = global_eager_cache.begin();
    while (i != global_eager_cache.end() && *i < range[0])
        ++i;

    while (i != global_eager_cache.end() && *i <= range[1]) {
        std::cout << *i << std::endl;
        ++i;
    }
}

int main() {
    // Fill eager cache
    fillEagerCache();

    int numberOfLines;
    std::cin >> numberOfLines;
    while (numberOfLines-- != 0) {
        runCase();

        // Print extra new line between test cases, but not after the last one
        if (numberOfLines != 0)
            std::cout << std::endl;
    }
    return 0;
}
