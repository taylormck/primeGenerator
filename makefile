runc: PrimeGenerator
	./PrimeGenerator

runci: PrimeGenerator
	./PrimeGenerator < primeGenerator.in

diffc: PrimeGenerator
	./PrimeGenerator < primeGenerator.in > primeGenerator.tmp
	diff primeGenerator.out primeGenerator.tmp
	rm primeGenerator.tmp

PrimeGenerator: primeGenerator.cpp
	g++ -pedantic -Wall primeGenerator.cpp -o PrimeGenerator

runr: primeGenerator.rb
	ruby primeGenerator.rb

runri: primeGenerator.rb
	ruby primeGenerator.rb < primeGenerator.in

diffr: primeGenerator.rb
	ruby primeGenerator.rb < primeGenerator.in > primeGenerator.tmp
	diff primeGenerator.out primeGenerator.tmp
	rm -f primeGenerator.tmp

test: diffc diffr

clean:
	rm -f primeGenerator.tmp
	rm -f PrimeGenerator
