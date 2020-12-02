#include "partie.h"
#include "grille.h"
#include "coordonnees.h"
void tourJcJ(){
    
}
void partieJcJ(){

    Grille_j *j1=NULL, *j2=NULL;
    j1 =(Grille_j *)malloc(sizeof(Grille_j));
    j2 = (Grille_j *)malloc(sizeof(Grille_j));

    initaliser_grille(j1,j2);
    iniBateau(j1,j2);
    printf("Joueur 1 placer vos bateaux !\n");
    j1 = placerBateau(j1,&j1->porteAvion);
    j1 = placerBateau(j1, &j1->croiseur);
    j1 = placerBateau(j1, &j1->contre_torpilleur);
    j1 = placerBateau(j1, &j1->sous_marin);
    j1 = placerBateau(j1, &j1->torpilleur);
    printf("Joueur 2 placer vos bateaux !\n");
    j2 = placerBateau(j2, &j2->porteAvion);
    j2 = placerBateau(j2, &j2->croiseur);
    j2 = placerBateau(j2, &j2->contre_torpilleur);
    j2 = placerBateau(j2, &j2->sous_marin);
    j2 = placerBateau(j2, &j2->torpilleur);
} 


int main(int argc, char const *argv[])
{
    partieJcJ();
   return 0;
}