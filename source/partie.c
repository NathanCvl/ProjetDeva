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
        return 1;
    }
    if ((j2->contre_torpilleur.vieBateau + j2->croiseur.vieBateau + j2->porteAvion.vieBateau + j2->sous_marin.vieBateau + j2->torpilleur.vieBateau) == 0)
    {
        return -1;
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
    j1 = placerBateau(j1, &j1->porteAvion, 0,j2);
    j1 = placerBateau(j1, &j1->croiseur, 0,j2);
    j1 = placerBateau(j1, &j1->contre_torpilleur, 0,j2);
    j1 = placerBateau(j1, &j1->sous_marin, 0,j2);
    j1 = placerBateau(j1, &j1->torpilleur,0,j2);
    printf("Joueur 2 placer vos bateaux !\n");
    j2 = placerBateau(j2, &j2->porteAvion,JouB,j1);
    j2 = placerBateau(j2, &j2->croiseur,JouB,j1);
    j2 = placerBateau(j2, &j2->contre_torpilleur,JouB,j1);
    j2 = placerBateau(j2, &j2->sous_marin,JouB,j1);
    j2 = placerBateau(j2, &j2->torpilleur,JouB,j1);
}

int tourJ(Grille_j *j1,Grille_j *j2,int JouB){
    int toucher;
    // joueur 1 attaque le jouer 2;
    int x;
    //si le joueur touche un bateau il rejoue

    while (etat(j1, j2) == 0)
    {

        printf("%s attaque %s \n", j1->nomJoueur, j2->nomJoueur);
        toucher = attaque(j1, j2, 0, 1, 0);
        if (toucher==1)
        {
            printf("%s attaque %s \n", j1->nomJoueur, j2->nomJoueur);
            toucher = attaque(j1, j2, 0, 1, 0);
            afficherGrille(j1->grilleTire);
          
            
        }else
        {
            printf("%s attaque %s \n", j2->nomJoueur, j1->nomJoueur);
            toucher = attaque(j2, j1, JouB, 1, 0);
        
            if (toucher == 1)
            {
                printf("%s attaque %s \n",j2->nomJoueur,j1->nomJoueur);
                toucher = attaque(j2, j1, JouB,1,1);
                afficherGrille(j2->grilleTire);
              
            }else if(toucher !=1)
            {
                
                tourJ(j1,j2,JouB);
            }
        }
    }
    if (etat(j1, j2) == 1)
    {
       return 1;
    }
    else if (etat(j1,j2)==-1)
    {
        return 0;
    }
    return -1;
}
void partie(int JouB,char nom[]){
    #if defined(WIN32)
    GREEN
    printf(" ____        _        _ _ _                               _      \n");
    printf("| __ )  __ _| |_ __ _(_) | | ___   _ __   __ ___   ____ _| | ___ \n");
    printf("|  _ \\ / _` | __/ _` | | | |/ _ \\ | '_ \\ / _` \\ \\ / / _` | |/ _ \\\n");
    printf("| |_) | (_| | || (_| | | | |  __/ | | | | (_| |\\ V / (_| | |  __/\n");
    printf("|____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| |_|\\__,_| \\_/ \\__,_|_|\\___|\n\n");
    BLUE
    printf( "        _     _     _ "  "__-=-//__  __\\\\-=-__"  " _     _     _        \n" );
    printf( ".-.,.-'`(,.-'`(,.-'`(,"  "\\_______/"  ".."  "\\_______/"  ",)`'-.,)`'-.,)`'-.,¸.-.\n\n" );
    RESET
    #elif __APPLE__
    printf(GREEN);
    printf(" ____        _        _ _ _                               _      \n");
    printf("| __ )  __ _| |_ __ _(_) | | ___   _ __   __ ___   ____ _| | ___ \n");
    printf("|  _ \\ / _` | __/ _` | | | |/ _ \\ | '_ \\ / _` \\ \\ / / _` | |/ _ \\\n");
    printf("| |_) | (_| | || (_| | | | |  __/ | | | | (_| |\\ V / (_| | |  __/\n");
    printf("|____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| |_|\\__,_| \\_/ \\__,_|_|\\___|\n\n");
    printf(BLUE "        _     _     _ " RESET "__-=-//__  __\\\\-=-__" BLUE " _     _     _        \n" RESET);
    printf( BLUE ".-.,.-'`(,.-'`(,.-'`(," RESET "\\_______/" BLUE ".." RESET "\\_______/" BLUE ",)`'-.,)`'-.,)`'-.,¸.-.\n\n" RESET);
    #endif
    Grille_j *j1=NULL, *j2=NULL;
    int gagnant;
    char rejouer[10];
    j1 =(Grille_j *)malloc(sizeof(Grille_j));
    j2 = (Grille_j *)malloc(sizeof(Grille_j));
    if (JouB==0)
    {
        printf("Pseudo joueur 1 : \n ");
        scanf("%s",(*j1).nomJoueur);
        printf("Pseudo joueur 2 : \n");
        scanf("%s",(*j2).nomJoueur);
    }else
    {
        printf("Pseudo joueur 1 : \n ");
        scanf("%s", j1->nomJoueur);
        char nom[] = "Ordinateur";
        strcpy(j2->nomJoueur,nom);
    }
    printf("voulez vous reprendre une partie ? ");
    scanf("%s",rejouer);
    initialiser_grille(j1,j2);
    iniBateau(j1,j2);
    if (strcmp(rejouer, "Oui") == 0)
    {
        ChargerGrille(j1->grille, "grilleJ1.txt");
        ChargerGrille(j1->grilleTire, "grilleTireJ1.txt");
        ChargerGrille(j2->grille, "grilleJ2.txt");
        ChargerGrille(j2->grille, "grilleTireJ2.txt");
    }else
    {
        Bat_grille(j1, j2, JouB);
    }
    
    gagnant=tourJ(j1,j2,JouB);
    if (gagnant ==1)
    {
        printf("%s gagne la partie !\n",j2->nomJoueur);
    }else if(gagnant==0){

        printf("%s gagne la partie !\n", j1->nomJoueur);
    }
    
    free(j1);
    free(j2);
}
