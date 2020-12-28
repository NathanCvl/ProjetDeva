#include "../header/sauvegarde.h"


void SaveGrille(int grille[TGRILLE][TGRILLE],FILE* fichier,char nom[])
{
    int i,j;
    fichier = fopen(nom,"w+");
  
    for (i = 0; i < TGRILLE; i++)
    {
        for (j = 0; j < TGRILLE; j++)
        {
            fprintf(fichier ,"%i",grille[i][j]);
        }
        fprintf(fichier,"\n");
    }
    fclose(fichier);
}
void ChargerGrille(int grille[TGRILLE][TGRILLE], FILE *file, char nom[])
{
    int i=0,j=0;
    file = fopen(nom, "r");
    char c = fgetc(file); /* lecture du 1er caractère du fichier */
    while (c != EOF) /* Tant qu'on est pas en fin de fichier */
    {
        if (c == '\n')
        {
            grille[i][j] = '\0'; /* on ajoute le caractère de fin de chaîne de caractères */
            i++, j = 0;       /* Ligne suivante, remise à 0 de l'index des caractères */
        }

        else
        {
            grille[i][j] = atoi(&c); /* affectation du caractère à l'index j */
            j++;           /* index suivant pour le caractère suivant */
        }

        c = fgetc(file); /* lecture du prochaine caractère */
    }
fclose(file);
}
