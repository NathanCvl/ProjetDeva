#include "jeux.h"

jeux initaliser_jeux()
{
    jeux h;
    int i, j;
    for (i = 0; i < TGRILLE; i++)
    {
        for (j = 0; j < TGRILLE; j++)
        {
            h.Grillejoueur1[i][j]=eau;
            h.GrilleJoueur2[i][j]=eau;
        }
    }
    return h;
}
void afficher_jeux(jeux p){
    int i, j;
    for (i = 0; i < TGRILLE; i++)
    {
        for (j = 0; j < TGRILLE; j++)
        {
            printf("%d",p.Grillejoueur1[i][j]);
            printf("%d", p.GrilleJoueur2[i][j]);
        }
    }
}
void type_bateau(jeux p){
    p.porte_avion.taille=Bat_porte_avion;
    p.croiseur.taille = Bat_croiseur;
    p.contre_torpilleur.taille = Bat_contre_torpilleur;
    p.sous_marin.taille = Bat_sous_marin;
    p.torpilleur.taille = Bat_torpilleur;
    
}

int main(int argc, char const *argv[])
{  
    jeux p;
    p=initaliser_jeux();
    afficher_jeux(p);

    return 0;
}
