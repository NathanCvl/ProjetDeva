#include "./header/partie.h"
#include "./header/sauvegarde.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    FILE * fichier =NULL;
    Grille_j *t=NULL;
    t=(Grille_j *)malloc(sizeof(Grille_j));
    initialiser_grille(t,t);
    SaveGrille(t->grille,fichier,"save.txt");
    return 0;
}