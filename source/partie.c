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
        
        assert(n <= RAND_MAX);

        int end = RAND_MAX / n; // truncate skew
        assert(end > 0);
        end *= n;
        int r;
        while ((r = rand()) >= end);

        return r % n;
    }
}
//Placement des bateaux
void Bat_grille(Grille_j *j1 ,Grille_j *j2,int JouB){
    printf("Joueur 1 placer vos bateaux !\n");
    j1 = placerBateau(j1, &j1->porteAvion, 0);
    j1 = placerBateau(j1, &j1->croiseur, 0);
    j1 = placerBateau(j1, &j1->contre_torpilleur, 0);
    j1 = placerBateau(j1, &j1->sous_marin, 0);
    j1 = placerBateau(j1, &j1->torpilleur,0);
    printf("Joueur 2 placer vos bateaux !\n");
    j2 = placerBateau(j2, &j2->porteAvion,JouB);
    j2 = placerBateau(j2, &j2->croiseur,JouB);
    j2 = placerBateau(j2, &j2->contre_torpilleur,JouB);
    j2 = placerBateau(j2, &j2->sous_marin,JouB);
    j2 = placerBateau(j2, &j2->torpilleur,JouB);
}

void tourJ(Grille_j *j1,Grille_j *j2,int JouB){
    int toucher;
    // joueur 1 attaque le jouer 2;
    
    //si le joueur touche un bateau il rejoue
    printf("j1 attaque j2 \n");
    toucher = attaque(j1, j2,1,1,0);
    while (etat(j1,j2)!=1)
    {

        if (toucher==1)
        {
            printf("j1 attaque j2 \n");
            toucher = attaque(j1, j2, 1,1,0);
            afficherGrille(j1->grilleTire);
        }else
        {
            printf("j2 attaque j1 \n");
            toucher = attaque(j2, j1, JouB,1,0);
            if (toucher == 1)
            {
                printf("j2 attaque j1 \n");
                toucher = attaque(j2, j1, JouB,1,1);
                afficherGrille(j2->grilleTire);
            }else if(toucher !=1)
            {
                tourJ(j1,j2,JouB);
            }
        }

    }
    
}
void partie(int JouB,char nom[]){
    Grille_j *j1=NULL, *j2=NULL;
    j1 =(Grille_j *)malloc(sizeof(Grille_j));
    j2 = (Grille_j *)malloc(sizeof(Grille_j));
    initialiser_grille(j1,j2);
    iniBateau(j1,j2);
    SaveGrille(j1->grille, nom);
    Bat_grille(j1,j2,JouB);
    tourJ(j1,j2,JouB);
    afficherGrille(j1->grille);
    afficherGrille(j2->grille);
    SaveGrille(j1->grille,"save2.txt");
    ChargerGrille(j1->grilleTire,"save2.txt");
    printf("grille charger");
    afficherGrille(j1->grilleTire);
    free(j1);
    free(j2);
}


