#!/usr/bin/env ruby -wKU
# Prime Generator

UPPER_LIMIT = 1000000000

# Perform the sieve itself
def sieve(table, b, e)
  lengthOfRange = e - b + 1

  # Generate small primes
  sqrt_end = Math.sqrt(e).floor
  smallPrimes = Array.new(sqrt_end + 1, true);

  for i in 2..sqrt_end
    if smallPrimes[i]
      j = i**2
      while j <= sqrt_end
        smallPrimes[j] = false
        j += i
      end
    end
  end

  for k in 2..sqrt_end
    if smallPrimes[k]
      i = [2, (b + k - 1) / k].max * k - b
      while i < lengthOfRange
        table[i] = false
        i += k
      end
    end
  end
end

# Set the bounds of the range to be valid
def setBoundsOnRange(range)
  # All prime numbers are >= 2
  # anything less than two won't be prime
  range[0] = [range[0], 2].max
  range[1] = [range[1], UPPER_LIMIT].min

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

# Read in the next line and print the primes the results
def runCase
  range = readLineIntoArray
  dist = range[1] - range[0] + 1

  table = Array.new(dist, true)
  sieve(table, range[0], range[1])

  for i in 0..dist
    if table.at(i)
      print i + range[0], "\n"
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
