#!/usr/bin/env ruby -wKU
# Prime Generator
require 'set' # set

# Set the bounds of the range to be valid
def setBoundsOnRange(range)
  # All prime numbers are >= 2
  # anything less than two won't be prime
  if range[0] < 2
    range[0] = 2
  end

  return range
end

# Read the next line and store it as an array of ints
def readLineIntoArray
  # Read the line in as an array of ints
  range = gets.strip.split(/\s+/).map(&:to_i)
  range.sort!
  range = setBoundsOnRange(range)
  return range
end

# @return true if n is prime
#         false otherwise
def isPrime(n)
  # Special case where n is even
  if n == 2
    return true
  elsif n % 2 == 0
    return false
  end

  sqrt_n = Math.sqrt(n)
  numbersToCheck = 3..sqrt_n
  numbersToCheck.step(2) do |i|
    if n % i == 0
      return false
    end
  end
  return true
end

# Takes in a range and returns a list of numbers that
# should be checked for primality, stripping numbers
# that are multiples of numbers earlier in the range
def getListOfNumbersToCheck(range)
  list = *(range[0]..range[1])

  i = 0
  while i < list.length
    smallerValue = list[i]
    j = i + 1
    while j < list.length
      largerValue = list[j]
      if largerValue % smallerValue == 0
        list.delete_at(j)
      elsif
        j += 1
      end
    end
    i += 1
  end

  return list
end

# Read in the next line and print the primes the results
def runCase
  range = readLineIntoArray
  numbersToCheck = getListOfNumbersToCheck(range)

  for i in numbersToCheck
    if isPrime(i)
      print i, "\n"
    end
  end
end

def main
  numberOfLines = gets.to_i
  numberOfLines.times do |i|
    runCase
    if i != numberOfLines - 1
      print "\n"
    end
  end
end

main
