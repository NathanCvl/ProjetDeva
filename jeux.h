#ifndef _JEUX_
#define _JEUX_
#define TGRILLE 10
#include <stdlib.h>
#include <stdio.h>
#define eau 0
#define Bat_porte_avion 5
#define Bat_croiseur 4
#define Bat_contre_torpilleur 3
#define Bat_sous_marin 3 
#define Bat_torpilleur 2
typedef struct
{
	int x, y;
}
Coordonnes;
typedef struct
{
	int sens;
	Coordonnes case_base;
	int taille;
} Bateau;

typedef struct{
	Bateau porte_avion, croiseur, contre_torpilleur, sous_marin, torpilleur;
	int Grillejoueur1[TGRILLE][TGRILLE];
	int GrilleJoueur2[TGRILLE][TGRILLE];
}jeux;

#endif