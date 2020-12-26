all : coordonnees.o grille.o partie.o bot.o
	gcc -o all coordonnees.o grille.o partie.o bot.o
coordonnees.o : coordonnees.c
	gcc -o coordonnees.o -c coordonnees.c -Wall -O

grille.o : grille.c
	gcc -o grille.o -c grille.c -Wall -O
partie.o : partie.c
	gcc -o partie.o -c partie.c -Wall -O 
bot.o :  bot.c
	gcc -o bot.o -c bot.c -Wall -O 
clean:
	rm -rf *.o
mrproper: clean
	rm -rf all