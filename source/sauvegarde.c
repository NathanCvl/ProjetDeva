#include "../header/sauvegarde.h"
#include "../header/grille.h"


void SaveGrille(int grille[TGRILLE][TGRILLE],FILE* fichier,char nom[])
{
    int i,j;
    fichier = fopen(nom,"w+");
    fprintf(fichier, "\n  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|\n" );
    fprintf(fichier, "--+---+---+---+---+---+---+---+---+---+---+" );
    for (i = 0; i < TGRILLE; i++)
    {
        fprintf(fichier, "\n%c |" , 'A' + i);
        for (j = 0; j < TGRILLE; j++)
        {
            if (grille[i][j] == eau)
            {
                fprintf(fichier,"%s",  "   "  "|" );
            }
            else if (grille[i][j] == eau_touche)
            {
                fprintf(fichier,"%s",  " * "  "|" );
            }
            else if (grille[i][j] == ID_contre_torpilleur || grille[i][j] == ID_croiseur || grille[i][j] == ID_porteAvion || grille[i][j] == ID_sous_marin || grille[i][j] == ID_torpilleur)
            {
                fprintf(fichier,"%s",  "[$]"  "|" );
            }
            else
            {
                fprintf(fichier,"%s",  "[$]"  "|" );
            }
        }
        fprintf(fichier,"\n");
        fprintf(fichier, "--+---+---+---+---+---+---+---+---+---+---+" );
    }
    fprintf(fichier,"\n");
    }
    
