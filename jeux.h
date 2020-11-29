#ifndef _JEUX_
#define _JEUX_
#include "bateau.h"
#define TGRILLE 10
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// constante grille
#define eau 0
#define eau_touche 1

// couleur 
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
//affichage grille
char LIGNE[] = "--+---+---+---+---+---+---+---+---+---+---+",
		   EAU[] = "   |",
		   EAU_T[] = BLUE " X " RESET "|",
		   BAT[] = GREEN " ▓" RESET " |",
		   BAT_T[] = RED " ▓" RESET "|";

/*
definition de la grille avec le nom des bateau et leurs type et la définiton de deux matrice qui 
represente la grille du joueur 1 et 2 ou du joueur 1 contre l'IA on
*/
typedef struct
{
	Bateau porteAvion,croiseur,contre_torpilleur,sous_marin,torpilleur;
	int grille[TGRILLE][TGRILLE];
	int grilleTire[TGRILLE][TGRILLE];
}Grille_j;


#endif