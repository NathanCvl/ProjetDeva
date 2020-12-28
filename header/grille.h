#ifndef _GRILLE_
#define _GRILLE_
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
//on doit definir des points de vie pour les bateaux pour definir leurs etats dans la partie quand la vie du bateau est a 0 le bateau est coule
//on devra donc definir un code pour chaque bateau pour pouvoir recuperer sur quel bateau on tire
#define TGRILLE 10

// constante grille
#define eau 0
#define eau_touche 1
#if defined(WIN32)
#include <windows.h>

	#define RED SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	#define GREEN SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	#define BLUE SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	#define CYAN SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	#define RESET SetConsoleTextAttribute(hConsole, saved_attributes);

#elif __APPLE__
// couleur
// source : https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
#endif


/*
definition de la grille avec le nom des bateaux et leurs types et la definiton de deux matrices qui 
represente la grille du joueur 1 et 2 ou du joueur 1 contre l'IA
*/

typedef struct
{	int vieBateau;
	int idBateau;
	char *nom;
}Bateau;
typedef struct {
	int grille[TGRILLE][TGRILLE];
	int grilleTire[TGRILLE][TGRILLE];
	int vie;
	Bateau porteAvion, croiseur, contre_torpilleur, sous_marin, torpilleur;

}Grille_j;
void initialiser_grille(Grille_j *j1, Grille_j *j2);
void iniBateau(Grille_j *j, Grille_j *h);
int attaque(Grille_j *joueur1, Grille_j *joueur2,int JouB);
void afficherGrille(int grille[TGRILLE][TGRILLE]);
Grille_j *placerBateau(Grille_j *g, Bateau *b,int JouB);
int generer_borne(int n);
char *cAleatoire();
#endif