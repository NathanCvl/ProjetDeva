#ifndef _JEUX_
#define _JEUX_
//Point de vie et taille du bateau
#define t_porte_avion 5
#define t_croiseur 4
#define t_contre_torpilleur 3
#define t_sous_marin 3
#define t_torpilleur 2
//idbateau
#define ID_porteAvion 500
#define ID_croiseur 501
#define ID_contre_torpilleur 502
#define ID_sous_marin 503
#define ID_torpilleur 504
#define bat_toucher 505
//definition d'un type bateau avec leurs ID et leurs points de vie
//on doit définir des points de vie pour les bateaux pour définir leurs états dans la partie quand la vie du bateau est à 0 le bateau est coulé
//on devra donc définir un code pour chaque bateau pour pouvoir récupéré sur quel bateau on tire
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
{	int vieBateau;
	int idBateau;
	char *nom;
}Bateau;
typedef struct {
	int grille[TGRILLE][TGRILLE];
	int grilleTire[TGRILLE][TGRILLE];
	Bateau porteAvion, croiseur, contre_torpilleur, sous_marin, torpilleur;

}Grille_j;

void tire(Grille_j *joueur1, Grille_j *joueur2);
#endif