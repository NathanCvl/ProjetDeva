#include "partie.h"
#include "grille.h"
#include "coordonnees.h"
//retourne 1 si un joueur a gagner la partie 
int etat(Grille_j *j1, Grille_j *j2)
{
    int enVie = 0;
    if (j1->contre_torpilleur.vieBateau == 0)
    {
        j1->vie--;
        j1->contre_torpilleur.vieBateau = -1;
    }
    else if (j1->porteAvion.vieBateau == 0)
    {
        j1->vie--;
        j1->porteAvion.vieBateau = -1;
    }
    else if (j1->sous_marin.vieBateau == 0)
    {
        j1->vie--;
        j1->sous_marin.vieBateau = -1;
    }
    else if (j1->torpilleur.vieBateau == 0)
    {
        j1->vie--;
        j1->torpilleur.vieBateau = -1;
    }
    if (j1->croiseur.vieBateau == 0)
    {
        j1->vie--;
        j1->croiseur.vieBateau = -1;
    }
    //
    if (j2->contre_torpilleur.vieBateau == 0)
    {
        j2->vie--;
        j2->contre_torpilleur.vieBateau = -1;
    }
    else if (j2->porteAvion.vieBateau == 0)
    {
        j2->vie--;
        j2->porteAvion.vieBateau = -1;
    }
    else if (j2->sous_marin.vieBateau == 0)
    {
        j2->vie--;
        j2->sous_marin.vieBateau = -1;
    }
    else if (j2->torpilleur.vieBateau == 0)
    {
        j2->vie--;
        j2->torpilleur.vieBateau = -1;
    }
    if (j2->croiseur.vieBateau == 0)
    {
        j2->vie--;
        j2->croiseur.vieBateau = -1;
    }
    if (j1->vie <= 0)
    {
        printf("Joueur 2 à gagner !\n");
        return 1;
    }
    if (j2->vie <= 0)
    {
        printf("Joueur 1 à gagner !\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

//Placement des bateaux
void Bat_grille(Grille_j *j1 ,Grille_j *j2){
    printf("Joueur 1 placer vos bateaux !\n");
    j1 = placerBateau(j1, &j1->porteAvion);
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
void tourJcJ(Grille_j *j1,Grille_j *j2){
    int toucher;
    int x = 0;
    printf("Le joueur 1 commence\n");
    // joueur 1 attaque le jouer 2;
    
    //si le joueur touche un bateau il rejoue
    while (x!=1)
    {
        toucher = attaque(j1, j2);
        if (toucher==1 && x!=1)
        {
            while (toucher == 1 && x != 1)
            {
                toucher = attaque(j1, j2);
                x = etat(j1, j2);
            }
        }
        else if (x != 1)
        {
            toucher = attaque(j2, j1);
            x = etat(j1, j2);
            while (toucher == 1 && x != 1)
            {
                toucher = attaque(j2, j1);
                x = etat(j1, j2);
            }
        }
        
        
        
    }
}
void partieJcJ(){

    Grille_j *j1=NULL, *j2=NULL;
    j1 =(Grille_j *)malloc(sizeof(Grille_j));
    j2 = (Grille_j *)malloc(sizeof(Grille_j));

    initialiser_grille(j1,j2);
    iniBateau(j1,j2);
    Bat_grille(j1,j2);
    tourJcJ(j1,j2);

 
} 


int main(int argc, char const *argv[])
{
    partieJcJ();
   return 0;
}