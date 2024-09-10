all: Driver

Driver: Driver.o Primes.o
	gcc -Wall -Wextra -std=c99 -o Driver Driver.o Primes.o

Driver.o: Driver.c Primes.h
	gcc -Wall -Wextra -std=c99 -c Driver.c

Primes.o: Primes.c Primes.h
	gcc -Wall -Wextra -std=c99 -c Primes.c

clean:
	rm -f *.o Driver

tar:
	tar -cvf William-Schmitz-HW1.tar Driver.c Primes.c Primes.h Makefile README.txt
