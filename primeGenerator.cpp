// Prime Generator in C++
#include <iostream>
#include <cmath>    // sqrt
#include <list>

typedef std::list<int> my_list_type;
typedef my_list_type::iterator my_list_type_iterator;

/*
 * Set the bounds of the range to be valid
 */
void setBoundsOnRange(int * range) {
  // All prime numbers are >= 2
  // anything less than two won't be prime
    if (range[0] < 2) {
        range[0] = 2;
    }
}

/*
 * Read the next line and store it as an array of ints
 */
void readRange(int * range) {
    std::cin >> range[0];
    std::cin >> range[1];

    setBoundsOnRange(range);
}

/*
 * @return true if n is prime
 *         false otherwise
 */
bool isPrime(int n) {
    // If n is even
    if (n == 2)
        return true;
    else if ((n & 1) == 0)
        return false;

    int sqrt_n = static_cast<int> (sqrt(n));

    for (int i = 2; i <= sqrt_n; ++i) {
        if (n % i == 0)
          return false;
    }

    // If we reach this point, n is prime
    return true;
}

/*
 * Takes in a range and returns a list of numbers that
 * should be checked for primality, stripping numbers
 * that are multiples of numbers earlier in the range
 */
void getListOfNumbersToCheck(int const * range, my_list_type& numbersToCheck) {
    // Create the full list
    for (int i = range[0]; i <= range[1]; ++i)
        numbersToCheck.push_back(i);

    // Use sieve table removal
    for (my_list_type_iterator i = numbersToCheck.begin();
         i != numbersToCheck.end();
         ++i) {
        my_list_type_iterator j = i;
        ++j;
        while (j != numbersToCheck.end()) {
            if (*j % *i == 0)
                j = numbersToCheck.erase(j);
            else
                ++j;
        }
    }
}

/*
 * Read in the next line and print the primes the results
 */
void runCase() {
    int range[2];
    readRange(range);
    // my_list_type numbersToCheck;
    // getListOfNumbersToCheck(range, numbersToCheck);

    // for (my_list_type_iterator i = numbersToCheck.begin();
    //      i != numbersToCheck.end(); ++i) {
    //     if (isPrime(*i))
    //         std::cout << *i << std::endl;
    // }

    for (int i = range[0]; i <= range[1]; ++i) {
        if (isPrime(i))
            std::cout << i << std::endl;
    }
}

int main() {
    int numberOfLines;
    std::cin >> numberOfLines;
    while (numberOfLines-- != 0) {
        runCase();
        if (numberOfLines != 0)
            std::cout << std::endl;
    }
    return 0;
}