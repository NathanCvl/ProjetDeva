#ifndef _BATEAU_
#define _BATEAU_
#include <stdio.h>
#include <stdio.h>
#include "jeux.h"
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
//definition d'un type bateau avec leurs ID et leurs points de vie
typedef struct
{
    int vieBateau;
    int idBateau;
}Bateau;
void iniBateau(Grille_j *j);
#endif