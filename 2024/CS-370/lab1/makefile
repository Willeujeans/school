CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = Driver.o Primes.o

all: Driver

Driver: $(OBJ)
	$(CC) $(CFLAGS) -o Driver $(OBJ)

Driver.o: Driver.c Primes.h
	$(CC) $(CFLAGS) -c Driver.c

Primes.o: Primes.c Primes.h
	$(CC) $(CFLAGS) -c Primes.c

clean:
	rm -f *.o Driver

tar:
	tar -cvf $(USER)-HW1.tar Driver.c Primes.c Primes.h Makefile README.txt
