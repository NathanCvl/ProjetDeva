#include "coordonnees.h"
#include "grille.h"


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

void iniBateau(Grille_j *j)
{
    j->contre_torpilleur.idBateau = ID_contre_torpilleur;
    j->porteAvion.idBateau = ID_porteAvion;
    j->sous_marin.idBateau = ID_sous_marin;
    j->torpilleur.idBateau = ID_torpilleur;
    j->croiseur.idBateau = ID_croiseur;

    j->porteAvion.vieBateau = t_porte_avion;
    j->sous_marin.vieBateau = t_sous_marin;
    j->torpilleur.vieBateau = t_torpilleur;
    j->croiseur.vieBateau = t_croiseur;
    j->contre_torpilleur.vieBateau = t_contre_torpilleur;

    j->porteAvion.nom= "porte_avion";
    j->sous_marin.nom = "sous marin";
    j->torpilleur.nom = "torpilleur";
    j->croiseur.nom = "croiseur";
    j->contre_torpilleur.nom = "contre torpilleur";
    
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
            if (c_bateau.x+b.vieBateau >TGRILLE)
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
        else if (c_bateau.y+b.vieBateau > TGRILLE){
            printf("Limite de la grille dépasser\n");
            c_valide = false;
         }
        else
        //on verifie si un bateau n'a pas été placer avant
        {
            for (i = c_bateau.x; i < c_bateau.x+b.vieBateau; i++)
            {
                if (g.grille[c_bateau.x][i] != eau)
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
        for (i = c_bateau.x; i < c_bateau.x + b.vieBateau; i++)
        {
            g.grille[i][c_bateau.y] = b.idBateau;
        }

    }
    else
    {
        for (i = c_bateau.y; i < c_bateau.y+ b.vieBateau; i++)
        {
            g.grille[c_bateau.x][i] = b.idBateau;
        }
    }    
    return g;
}
//ici on crée la fonction tire qui va tiré sur la grille énnemie le but étant de montré sUR la grille si un bateau a été touché,
//sans afficher la grille énemie au joueur qui tire 
int attaque(Grille_j *joueur1,Grille_j *joueur2){
    int touche = 0;
    Coordonnees tire;
    int idcase;
    char c_tire[4];
    printf("Sur quel case voulez vous tiré ?");
    scanf("%s",c_tire);
    tire = caracToCdn(c_tire);
    idcase = joueur2->grille[tire.x][tire.y];
    if (idcase == bat_toucher)
    {
        printf("Vous avez déja attaquer cette case ! \n ");
        printf("Sur quel case voulez vous tiré ?\n");
        scanf("%s", c_tire);
    }
    else if (idcase== eau)
    {   printf("tire raté\n");
        joueur1->grilleTire[tire.x][tire.y]=eau_touche;
        joueur2->grille[tire.x][tire.y]=eau_touche;
    }
    else
    {
        touche=1;
        printf("Vous avez toucher un bateau !\n");
        joueur1->grilleTire[tire.x][tire.y] = bat_toucher;
        joueur2->grille[tire.x][tire.y]=bat_toucher;
        switch (idcase)
        {
        case ID_porteAvion:
            joueur2->porteAvion.vieBateau--;
            break;
        case ID_contre_torpilleur:
            joueur2->contre_torpilleur.vieBateau--;
            break;
        case ID_croiseur:
            joueur2->croiseur.vieBateau--;
            break;
        case ID_sous_marin:
            joueur2->sous_marin.vieBateau--;
            break;
        case ID_torpilleur: 
            joueur2->torpilleur.vieBateau--;

        default: 
            printf("Erreur...(id inconnue)\n");
            break;
    }

    }
    return touche;
    
}
void etatBateau(Bateau t)
{
    if (t.vieBateau >= 1)
    {
        printf("le bateau %s lui reste : %d point de vie ! ", t.nom, t.vieBateau);
    }
    else
    {
        printf("le bateau %s viens d'étre coulé...", t.nom);
    }
}

int main(int argc, char const *argv[])
{
    char test[10] = "B9V";
    Coordonnees c;
    Grille_j p,j2;
    p=initaliser_grille(p);
    j2=initaliser_grille(j2);
    iniBateau(&j2);
    iniBateau(&p);
    j2= placerBateau(j2, j2.porteAvion);
    afficherGrille(j2.grille);
    printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
    attaque(&p,&j2);
    etatBateau(j2.porteAvion);
    afficherGrille(j2.grille);
    return 0;
}
