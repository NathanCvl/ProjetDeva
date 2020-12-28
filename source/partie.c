#include "../header/partie.h"
#include "../header/sauvegarde.h"
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

//retourne 1 si un joueur a gagner la partie
int etat(Grille_j *j1, Grille_j *j2)
{
  
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
        while ((r = rand()) >= end);

        return r % n;
    }
}
//Placement des bateaux
void Bat_grille(Grille_j *j1 ,Grille_j *j2,int JouB){
    printf("Joueur 1 placer vos bateaux !\n");
    j1 = placerBateau(j1, &j1->porteAvion, 1);
    j1 = placerBateau(j1, &j1->croiseur, 1);
    j1 = placerBateau(j1, &j1->contre_torpilleur, 1);
    j1 = placerBateau(j1, &j1->sous_marin, 1);
    j1 = placerBateau(j1, &j1->torpilleur,1);
    printf("Joueur 2 placer vos bateaux !\n");
    j2 = placerBateau(j2, &j2->porteAvion,1);
    j2 = placerBateau(j2, &j2->croiseur,1);
    j2 = placerBateau(j2, &j2->contre_torpilleur,1);
    j2 = placerBateau(j2, &j2->sous_marin,1);
    j2 = placerBateau(j2, &j2->torpilleur,1);
}

void tourJ(Grille_j *j1,Grille_j *j2,int JouB){
    int toucher;
    int x = 0;
    // joueur 1 attaque le jouer 2;
    
    //si le joueur touche un bateau il rejoue
    toucher = attaque(j1, j2,1);
    while (etat(j1,j2)==0)
    {

        if (toucher==1)
        {
            printf("j1 attaque j2 \n");
            toucher = attaque(j1, j2, 1);
            afficherGrille(j1->grilleTire);
        }else
        {
            printf("j2 attaque j1 \n");
            toucher = attaque(j2, j1, JouB);
            if (toucher == 1)
            {
                printf("j2 attaque j1 \n");
                toucher = attaque(j2, j1, JouB);
                afficherGrille(j2->grilleTire);
            }else if(toucher !=1)
            {
                tourJ(j1,j2,JouB);
            }
        }

    }
    
}
void partie(int JouB,FILE* fichier,char nom[]){
    Grille_j *j1=NULL, *j2=NULL;
    j1 =(Grille_j *)malloc(sizeof(Grille_j));
    j2 = (Grille_j *)malloc(sizeof(Grille_j));

    initialiser_grille(j1,j2);
    iniBateau(j1,j2);
    SaveGrille(j1->grille, fichier, nom);

    Bat_grille(j1,j2,JouB);
    tourJ(j1,j2,JouB);
    afficherGrille(j1->grille);
    afficherGrille(j2->grille);
    SaveGrille(j1->grille, fichier, "save2.txt");
}


