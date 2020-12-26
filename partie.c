#include "partie.h"
#include "grille.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

    //retourne 1 si un joueur a gagner la partie
    int etat(Grille_j *j1, Grille_j *j2)
{
    /*
    if (j1->contre_torpilleur.vieBateau == 0)
    {
        j1->vie--;
        j1->contre_torpilleur.vieBateau = -1;
        printf("Bateau couler");
    }
    else if (j1->porteAvion.vieBateau == 0)
    {
        j1->vie--;
        j1->porteAvion.vieBateau = -1;
        printf("Bateau couler");
    }
    else if (j1->sous_marin.vieBateau == 0)
    {
        j1->vie--;
        j1->sous_marin.vieBateau = -1;
        printf("Bateau couler");
    }
    else if (j1->torpilleur.vieBateau == 0)
    {
        j1->vie--;
        j1->torpilleur.vieBateau = -1;
        printf("Bateau couler");
    }
    else if (j1->croiseur.vieBateau == 0)
    {
        j1->vie--;
        j1->croiseur.vieBateau = -1;
        printf("Bateau couler");
    }
    //
    else if (j2->contre_torpilleur.vieBateau == 0)
    {
        j2->vie--;
        j2->contre_torpilleur.vieBateau = -1;
        printf("Bateau couler");
    }
    else if (j2->porteAvion.vieBateau == 0)
    {
        printf("Bateau couler");
        j2->vie--;
        j2->porteAvion.vieBateau = -1;
    }
    else if (j2->sous_marin.vieBateau == 0)
    {
        j2->vie--;
        j2->sous_marin.vieBateau = -1;
        printf("Bateau couler");
    }
    else if (j2->torpilleur.vieBateau == 0)
    {
        j2->vie--;
        j2->torpilleur.vieBateau = -1;
        printf("Bateau couler");
    }
    else if (j2->croiseur.vieBateau == 0)
    {
        j2->vie--;
        j2->croiseur.vieBateau = -1;
        printf("Bateau couler");
    }
    if (j1->vie == 0)
    {
        printf("Joueur 2 à gagner !\n");
        return 1;
    }
    if (j2->vie == 0)
    {
        printf("Joueur 1 à gagner !\n");
        return 1;
    }
    else
    {
        return 0;
    }*/
    if ((j1->contre_torpilleur.vieBateau+j1->croiseur.vieBateau+j1->porteAvion.vieBateau+j1->sous_marin.vieBateau+j1->torpilleur.vieBateau)==0)
    {
        printf("J2 gagne");
        return 1;
    }
    if ((j2->contre_torpilleur.vieBateau + j2->croiseur.vieBateau + j2->porteAvion.vieBateau + j2->sous_marin.vieBateau + j2->torpilleur.vieBateau) == 0)
    {
        printf("J1 gagne");
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int generer_borne(int n)
{
    if ((n - 1) == RAND_MAX)
    {
        return rand();
    }
    else
    {
        // Supporting larger values for n would requires an even more
        // elaborate implementation that combines multiple calls to rand()
        assert(n <= RAND_MAX);

        // Chop off all of the values that would cause skew...
        int end = RAND_MAX / n; // truncate skew
        assert(end > 0);
        end *= n;

        // ... and ignore results from rand() that fall above that limit.
        // (Worst case the loop condition should succeed 50% of the time,
        // so we can expect to bail out of this loop pretty quickly.)
        int r;
        while ((r = rand()) >= end)
            ;

        return r % n;
    }
}
//Placement des bateaux
void Bat_grille(Grille_j *j1 ,Grille_j *j2,int JouB){
    printf("Joueur 1 placer vos bateaux !\n");
    j1 = placerBateau(j1, &j1->porteAvion, JouB);
    j1 = placerBateau(j1, &j1->croiseur, JouB);
    j1 = placerBateau(j1, &j1->contre_torpilleur, JouB);
    j1 = placerBateau(j1, &j1->sous_marin, JouB);
    j1 = placerBateau(j1, &j1->torpilleur,JouB);
    printf("Joueur 2 placer vos bateaux !\n");

    j2 = placerBateau(j2, &j2->porteAvion,JouB);
    j2 = placerBateau(j2, &j2->croiseur,JouB);
    j2 = placerBateau(j2, &j2->contre_torpilleur,JouB);
    j2 = placerBateau(j2, &j2->sous_marin,JouB);
    j2 = placerBateau(j2, &j2->torpilleur,JouB);
}

void tourJ(Grille_j *j1,Grille_j *j2,int JouB){
    int toucher;
    int x = 0;
    printf("Le joueur 1 commence\n");
    // joueur 1 attaque le jouer 2;
    
    //si le joueur touche un bateau il rejoue
    while (x!=1)
    {

        if (attaque(j1, j2, 1)==1 )
        {
                x = etat(j1, j2);
            
        }
        else 
        {
            toucher = attaque(j2, j1,JouB);
            x = etat(j1, j2);
        }
    }
}

void partie(int JouB){

    Grille_j *j1=NULL, *j2=NULL;
    j1 =(Grille_j *)malloc(sizeof(Grille_j));
    j2 = (Grille_j *)malloc(sizeof(Grille_j));

    initialiser_grille(j1,j2);
    iniBateau(j1,j2);
    Bat_grille(j1,j2,JouB);
    tourJ(j1,j2,JouB);
    afficherGrille(j1->grille);
    afficherGrille(j2->grille);
}

int main(int argc, char const *argv[])
{   partie(1);
    
    return 0;
}
