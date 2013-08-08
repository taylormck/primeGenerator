run: primeGenerator.rb
	ruby primeGenerator.rb

runi: primeGenerator.rb
	ruby primeGenerator.rb < primeGenerator.in

test: primeGenerator.rb
	ruby primeGenerator.rb < primeGenerator.in > primeGenerator.tmp
	diff primeGenerator.out primeGenerator.tmp
	rm -f primeGenerator.tmp

clean:
	rm -f primeGenerator.tmp
