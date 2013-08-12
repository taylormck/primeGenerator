runc: PrimeGenerator
	PrimeGenerator

runci: PrimeGenerator
	PrimeGenerator < primeGenerator.in

diffc: PrimeGenerator
	PrimeGenerator < primeGenerator.in > primeGenerator.tmp
	diff primeGenerator.out primeGenerator.tmp
	rm primeGenerator.tmp

PrimeGenerator: primeGenerator.cpp
	g++ -pedantic -Wall primeGenerator.cpp -o PrimeGenerator

runp: primeGenerator.rb
	ruby primeGenerator.rb

runpi: primeGenerator.rb
	ruby primeGenerator.rb < primeGenerator.in

diffp: primeGenerator.rb
	ruby primeGenerator.rb < primeGenerator.in > primeGenerator.tmp
	diff primeGenerator.out primeGenerator.tmp
	rm -f primeGenerator.tmp

clean:
	rm -f primeGenerator.tmp
