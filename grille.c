#include "coordonnees.h"
#include "grille.h"


//TODO: placer bateau avec orientation : ok
//afficher grille avec coordonnées : ok 
//placer bateau ennemi par joueur ou IA :
//attaque joueur et/ou IA : 
//gérer le JcJ et JcIA :

//initialise la grille avec de l'eau partout donc une valeur egale a 0. Retourne type Grille
void initialiser_grille(Grille_j *j1, Grille_j *j2)
{
    j1->vie=5;
    j2->vie=5;
    int i, j;
    for (i = 0; i < TGRILLE; i++)
    {
        for (j = 0; j < TGRILLE; j++)
        {
            j1->grille[i][j]=eau;
            j1->grilleTire[i][j]=eau;
            j2->grille[i][j] = eau;
            j2->grilleTire[i][j] = eau;
        }
    }
}

void iniBateau(Grille_j *j, Grille_j *h)
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

    h->contre_torpilleur.idBateau = ID_contre_torpilleur;
    h->porteAvion.idBateau = ID_porteAvion;
    h->sous_marin.idBateau = ID_sous_marin;
    h->torpilleur.idBateau = ID_torpilleur;
    h->croiseur.idBateau = ID_croiseur;

    h->porteAvion.vieBateau = t_porte_avion;
    h->sous_marin.vieBateau = t_sous_marin;
    h->torpilleur.vieBateau = t_torpilleur;
    h->croiseur.vieBateau = t_croiseur;
    h->contre_torpilleur.vieBateau = t_contre_torpilleur;

    h->porteAvion.nom = "porte_avion";
    h->sous_marin.nom = "sous marin";
    h->torpilleur.nom = "torpilleur";
    h->croiseur.nom = "croiseur";
    h->contre_torpilleur.nom = "contre torpilleur";
    
}

//on affiche la grille avec differentes couleurs pour chaque situation : eau , eau deja touchee par un tir, un bateau ou alors un bateau touche
void afficherGrille(int grille[TGRILLE][TGRILLE])
{
    int i, j;


    printf("\n  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|\n");
    printf(MAGENTA "--+---+---+---+---+---+---+---+---+---+---+" RESET);
    for (i = 0; i < TGRILLE; i++)
    {
        printf(MAGENTA "\n%c |" RESET, 'A'+i);
        for (j = 0; j < TGRILLE; j++)
        {
            if (grille[i][j] == eau){
                printf("%s", BLUE "   "  MAGENTA "|" RESET);
            }
            else if (grille[i][j] == eau_touche){
                printf("%s", YELLOW " * " MAGENTA"|" RESET);
            }
            else if (grille[i][j] == ID_contre_torpilleur || grille[i][j] == ID_croiseur || grille[i][j] == ID_porteAvion || grille[i][j] == ID_sous_marin || grille[i][j] == ID_torpilleur)
            {
                printf("%s", GREEN "[$]" MAGENTA "|" RESET);
            }else
            {
                printf("%s", RED "[$]" MAGENTA "|" RESET);
            }
            
        }
        printf("\n");
        printf(MAGENTA "--+---+---+---+---+---+---+---+---+---+---+" RESET);
    }
    printf("\n");
}
//fonction pour placer les bateaux en fonction de leurs coordonnees et de leurs directions
//vie bateau est egale aussi a la taille du bateau en debut de partie
Grille_j *placerBateau(Grille_j *g, Bateau *b)
{
    system("clear");
    bool fini = false;
    int i;
    //chaine de caracteres pour recuperer les coordonnees du bateau;
    char coordonnee[4];
    afficherGrille(g->grille);
    printf("\n");
    Coordonnees *c_bateau = NULL;
    c_bateau = (Coordonnees *)malloc(sizeof(Coordonnees));
    while (fini == false)
    {
        bool c_valide = true;
        printf("Position du bateau : \n");
        scanf("%s",coordonnee);
        c_bateau = caracToCdn(coordonnee);
        // on test ici c'est les coordonnes rentré son comprise entre 0 et 9 ;
        if (c_bateau->x < 0 || c_bateau->y<0 || c_bateau->x > TGRILLE || c_bateau->y > TGRILLE)
        {
            printf("Mauvaise coordonnées veuillez réassayer\n");
            c_valide=false;
        }//on test ici quand on met le bateau a l'horizontal la taille du bateau ne dépasse pas la grille
        else if (c_bateau->placement == 'V')
        {
            if (c_bateau->x+b->vieBateau >TGRILLE)
            {
                printf("Limite de la grille dépasser\n");
                c_valide = false;
            }else
            //on verifie si un bateau n'a pas ete place avant
            {
                for ( i = c_bateau->x; i < b->vieBateau+c_bateau->x; i++)
                {
                    if (g->grille[i][c_bateau->y]!=eau)
                    {
                        printf("Il y'a déja un bateau ici\n");
                        c_valide =false;
                        break;
                    }     
                }
            }
        }
        else if (c_bateau->y+b->vieBateau > TGRILLE){
            printf("Limite de la grille dépasser\n");
            c_valide = false;
         }
        else
        //on verifie si un bateau n'a pas ete place avant
        {
            for (i = c_bateau->x; i < c_bateau->x+b->vieBateau; i++)
            {
                if (g->grille[i][c_bateau->y] != eau)
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
    if (c_bateau->placement == 'V')
    {
        for (i = c_bateau->x; i < c_bateau->x + b->vieBateau; i++)
        {
            g->grille[i][c_bateau->y] = b->idBateau;
        }

    }
    else
    {
        for (i = c_bateau->y; i < c_bateau->y+ b->vieBateau; i++)
        {
            g->grille[c_bateau->x][i] = b->idBateau;
        }
    }
    afficherGrille(g->grille);
    free(c_bateau);
    return g;
}
//ici on crée la fonction tire qui va tiré sur la grille énnemie le but étant de montré sUR la grille si un bateau a été touché,
//sans afficher la grille énemie au joueur qui tire 
// si retourne 1 le joueur retire 
int attaque(Grille_j *joueur1,Grille_j *joueur2){
    afficherGrille(joueur1->grilleTire);
    int touche = 0;
    Coordonnees *tire = NULL;
    tire = (Coordonnees *)malloc(sizeof(Coordonnees));
    int idcase;
    char c_tire[4];
    printf("Sur quel case voulez vous tiré ?\n");
    scanf("%s",c_tire);
    tire = caracToCdn(c_tire);
    idcase = joueur2->grille[tire->x][tire->y];
    if (idcase == bat_toucher)
    {
        printf("Vous avez déja attaquer cette case !\n");
        printf("Sur quel case voulez vous tiré ?\n");
        scanf("%s", c_tire);
    }
    else if (idcase== eau)
    {   printf("tire raté\n");
        joueur1->grilleTire[tire->x][tire->y]=eau_touche;
        joueur2->grille[tire->x][tire->y]=eau_touche;
    }
    else
    {
        touche=1;
        printf("Vous avez toucher un bateau !\n");
        joueur1->grilleTire[tire->x][tire->y] = bat_toucher;
        joueur2->grille[tire->x][tire->y]=bat_toucher;
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
            break;
    }

    }
    free(tire);
    return touche;
}


