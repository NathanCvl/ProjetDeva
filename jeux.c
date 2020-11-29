#include "jeux.h"
#include "coordonnees.h"
#include "bateau.h"

//TODO: placer  bateau avec orientation :ok
//afficher grille avec coordonnées : ok 
// placer bateau énemie par joueur ou IA :
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
            h.grilleTire[i][j]=eau;
            
        }
    }
    return h;
}


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
            else if (grille[i][j] == ID_contre_torpilleur || grille[i][j] == ID_croiseur || grille[i][j] == ID_porteAvion || grille[i][j] == ID_sous_marin || grille[i][j] == ID_torpilleur)
            {
                printf("%s", BAT);
            }else
            {
                printf("%s",BAT_T);
            }
            
        }
        printf("\n");
        printf("%s\n", LIGNE);
    }
}
//fonction pour placer les bateaux en fonction de leurs coordonnées et de leurs direction
//vie bateau est égal aussi a la taille du bateau en début de partie
Grille_j placerBateau(Grille_j g, Bateau b)
{
    system("clear");
    bool fini = false;
    int i;
    //chaine de caractere pour récuperer les coordonnées du bateau;
    char coordonnee[4];
    afficherGrille(g.grille);
    Coordonnees c_bateau; 
    while (fini==false)
    {
        bool c_valide = true;
        printf("Position du bateau : ");
        scanf("%s",coordonnee);
        c_bateau = caracToCdn(coordonnee);
        // on test ici c'est les coordonnes rentré son comprise entre 0 et 9 ;
        if (c_bateau.x < 0 || c_bateau.y<0 || c_bateau.x > TGRILLE || c_bateau.y > TGRILLE)
        {
            printf("Mauvaise coordonnées veuillez réassayer\n");
            c_valide=false;
        }//on test ici quand on met le bateau a l'horizontal la taille du bateau ne dépasse pas la grille
        else if (c_bateau.placement == 'V')
        {
            if (c_bateau.y+b.vieBateau >TGRILLE)
            {
                printf("Limite de la grille dépasser\n");
                c_valide = false;
            }else
            //on verifie si un bateau n'a pas été placer avant
            {
                for ( i = c_bateau.y; i < b.vieBateau+c_bateau.y; i++)
                {
                    if (g.grille[i][c_bateau.x]!=eau)
                    {
                        printf("Il y'a déja un bateau ici\n");
                        c_valide =false;
                        break;
                    }     
                }
            }
        }
        else if (c_bateau.x+b.vieBateau > TGRILLE){
            printf("Limite de la grille dépasser\n");
            c_valide = false;
         }
        else
        //on verifie si un bateau n'a pas été placer avant
        {
            for (i = c_bateau.x; i < c_bateau.x+b.vieBateau; i++)
            {
                if (g.grille[c_bateau.y][i] != eau)
                {
                    printf("Il y'a déja un bateau ici\n");
                    c_valide = false;
                    break;
                }
            }
        }
        if (c_valide == true)
        {
            fini=true;
        }
        
    }
    //on place le bateau sur la grille grace au coordonnées
    if (c_bateau.placement == 'V')
    {
        for (i = c_bateau.y; i < c_bateau.y + b.vieBateau; i++)
        {
            g.grille[i][c_bateau.x] = b.idBateau;
        }

    }
    else
    {
        for (i = c_bateau.x; i < c_bateau.x+ b.vieBateau; i++)
        {
            g.grille[c_bateau.y][i] = b.idBateau;
        }
    }
    printf("x : %d , y : %d ", c_bateau.x,c_bateau.y);
    
    return g;
}
//ici on crée la fonction tire qui va tiré sur la grille énnemie le but étant de montré sUR la grille si un bateau a été touché,
//sans afficher la grille énemie au joueur qui tire 
void tire (Grille_j *joueur1,Grille_j *joueur2){
    Coordonnees tire;
    char c_tire[4];
    afficherGrille(joueur1->grilleTire);
    printf("Sur quel case voulez vous tiré ?");
    scanf("%s",c_tire);
    tire = caracToCdn(c_tire);
    if (joueur2->grille[tire.x][tire.y]==eau)
    {
        joueur1->grilleTire[tire.x][tire.y]=eau_touche;
        joueur2->grille[tire.x][tire.y]=eau_touche;
    }
    else if (joueur2->grille[tire.x][tire.y]==Bateau)
    {
        joueur1->grilleTire[tire.x][tire.y]=Bateau_touche;
        joueur2->grille[tire.x][tire.y] = Bateau_touche;
    }

    
}
//on doit définir des points de vie pour les bateaux pour définir leurs états dans la partie quand la vie du bateau est à 0 le bateau est coulé 
//on devra donc définir un code pour chaque bateau pour pouvoir récupéré sur quel bateau on tire 
int main(int argc, char const *argv[])
{
    char test[10] = "B9V";
    Coordonnees c;
    Grille_j p;
    p=initaliser_grille(p);
    c=caracToCdn(test);
    p=placerBateau(p,"test",4);
    p = placerBateau(p, "truc", 5);
    afficherGrille(p.grille);
    return 0;
}
