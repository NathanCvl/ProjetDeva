#include "grille.h"

#include <stdlib.h>
#include <stdio.h>

/* Nathan */

void initaliser_grille(int tab[TGRILLE][TGRILLE]){
    int i,j;
    for ( i = 0; i < TGRILLE; i++)
    {
       for ( j = 0; j < TGRILLE; j++)
       {
        tab[i][j]=0;
       }
       
    }

}
void afficher_grille(int tab[TGRILLE][TGRILLE]){
    int i, j;
    for (i = 0; i < TGRILLE; i++)
    {
        for (j = 0; j < TGRILLE; j++)
        {
            printf("%d\t \t",tab[i][j]);
            printf("13432")
        }
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    int tab[TGRILLE][TGRILLE];
    initaliser_grille(tab);
    afficher_grille(tab);
    return 0;
}
void initialiser_grille(int *tab){
    
}
