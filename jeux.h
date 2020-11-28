#ifndef _JEUX_
#define _JEUX_
#define TGRILLE 10
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define eau 0
#define Bat_porte_avion 5
#define Bat_croiseur 4
#define Bat_contre_torpilleur 3
#define Bat_sous_marin 3 
#define Bat_torpilleur 2

/* définiton d'une structure coordonnees pour pour stocker la direction et les coordonnées dans une seul variable*/
typedef struct
{
	int x, y;
	char placement; /* pour définir la direction du bateau sur la grille */
} Coordonnees;
/*
definition de la grille avec le nom des bateau et leurs type et la définiton de deux matrice qui 
represente la grille du joueur 1 et 2 ou du joueur 1 contre l'IA
*/
typedef struct 
{
	int porte_avion, croiseur, contre_torpilleur, sous_marin, torpilleur;
	int grille1[TGRILLE][TGRILLE];
	int grille2[TGRILLE][TGRILLE];
}Grille;


#endif