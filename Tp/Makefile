# Définition du compilateur et des options
CC=gcc
CFLAGS=-Wall -pedantic -g

# Cibles principales
all: oubakki_ayoub_exo1

# Compilation des fichiers .c en .o
oubakkiAyoubExo1.o: oubakkiAyoubExo1.c oubakkiAyoubListeInt.h
	$(CC) $(CFLAGS) -c oubakkiAyoubExo1.c -o oubakkiAyoubExo1.o

oubakkiAyoubListeInt.o: oubakkiAyoubListeInt.c oubakkiAyoubListeInt.h
	$(CC) $(CFLAGS) -c oubakkiAyoubListeInt.c -o oubakkiAyoubListeInt.o

# Création de l'exécutable
oubakki_ayoub_exo1: oubakkiAyoubExo1.o oubakkiAyoubListeInt.o
	$(CC) $(CFLAGS) -o oubakki_ayoub_exo1 oubakkiAyoubExo1.o oubakkiAyoubListeInt.o

# Nettoyage des fichiers générés
clean:
	rm -f *.o oubakki_ayoub_exo1 oubakkiAyoubListeInt.o *.bin
