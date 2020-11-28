#include "coordonnees.h"
#include "jeux.h"

//TODO: placer  bateau avec orientation 
//afficher grille avec coordonnées
// placer bateau énémie par joueur ou IA
//attaque joueur et/ou IA
// gerer le JcJ et JcIA 



//initialise la grille avec de l'eau partout donc une valeur égale à 0.Retourne type Grille
Grille_j initaliser_grille(Grille_j h)
{
    int i, j;
    for (i = 0; i < TGRILLE; i++)
    {
        for (j = 0; j < TGRILLE; j++)
        {
            h.grille[i][j]=eau;
            
        }
    }
    return h;
}


//fonction pour placer les bateaux en fonction de leurs coordonnées et de leurs direction



//on affiche la grille avec differente couleur pour chaque situation : eau , eau déja touché par un tir, un bateau ou alors un batteau touché 
void afficherGrille(int grille[TGRILLE][TGRILLE])
{
    int i, j;


    printf("\n  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|\n");
    printf("%s\n",LIGNE);
    for (i = 0; i < TGRILLE; i++)
    {
        printf("%c |", 'A'+i);
        for (j = 0; j < TGRILLE; j++)
        {
            if (grille[i][j] == eau){
             printf("%s", EAU);
            }
            else if (grille[i][j] == eau_touche){
                printf("%s",EAU_T);
            }
   
        }
        printf("\n");
        printf("%s\n", LIGNE);
    }
}
Grille_j placerBateau(Grille_j g,char bateau[],int tailleBateau)
{   bool fini = false;
    int i;
    //chaine de caractere pour récuperer les coordonnées du bateau;
    char coordonnee[4];
    afficherGrille(g.grille);
    Coordonnees c_bateau; 
    while (fini==true)
    {
        printf("Position du bateau : ");
        scanf("%s",coordonnee);
        c_bateau = caracToCdn(coordonnee);
        // on test ici c'est les coordonnes rentré son comprise entre 0 et 9 ;
        if (c_bateau.x < 0 || c_bateau.y<0 || c_bateau.x > TGRILLE || c_bateau.y > TGRILLE)
        {
            printf("Mauvaise coordonnées veuillez réassayer");
        }//on test ici quand on met le bateau a l'horizontal la taille du bateau ne dépasse pas la grille
        else if (c_bateau.placement == 'H')
        {
            if (c_bateau.x+tailleBateau >TGRILLE)
            {
                printf("Limite de la grille dépasser");
            }else
            //on verifie si un bateau n'a pas été placer
            {
                for ( i = c_bateau.x; i < tailleBateau; i++)
                {
                    /* code */
                }
                
            }
            
            
        }
        
        
        
    }
    
    return g;
}
int main(int argc, char const *argv[])
{
    char test[10] = "B9V";
    Coordonnees c;
    Grille_j p;
    p=initaliser_grille(p);
    c=caracToCdn(test);
    printf("x:%d y:%d",c.x,c.y);
    return 0;
}
