CC=gcc
CFLAGS=-Wall -pedantic -g
all: util_rand

util_rand.o: util_rand.h util_rand.c
$(CC) -c util_rand.c -o util_rand.o

util_rand: util_rand.c util_rand.o
$(CC) $(CFLAGS) -o util_rand util_rand.c util_rand.o
clean:
rm *.o util_rand