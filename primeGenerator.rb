#!/usr/bin/env ruby -wKU
# Prime Generator

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
  sqrt_n = Math.sqrt(n)
  for i in 2..sqrt_n
    if n % i == 0
      return false
    end
  end
  return true
end

# Read in the next line and print the primes the results
def runCase
  range = readLineIntoArray

  for i in range[0]..range[1]
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
