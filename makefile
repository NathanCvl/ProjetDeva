
CC=gcc
CFLAGS=-Wall -O
LDFLAGS=
EXEC=mon_executable

all : coordonnees.o grille.o partie.o main.o sauvegarde.o
	$(CC) -o all coordonnees.o grille.o partie.o main.o sauvegarde.o
main.o:main.c
	$(CC) -o main.o -c main.c $(CFLAGS)
coordonnees.o : source/coordonnees.c
	$(CC) -o coordonnees.o -c source/coordonnees.c $(CFLAGS)
grille.o : source/grille.c
	$(CC) -o grille.o -c source/grille.c $(CFLAGS)
partie.o : source/partie.c
	$(CC) -o partie.o -c source/partie.c $(CFLAGS)
sauvegarde.o : source/sauvegarde.c
	$(CC) -o sauvegarde.o -c source/sauvegarde.c $(CFLAGS)
clean:
	rm -rf *.o
mrproper: clean
	rm -rf all