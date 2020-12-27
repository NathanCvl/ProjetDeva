#include "../header/sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>

void SaveGrille(int grille[TGRILLE][TGRILLE])
{
    int i, j;

    printf(MAGENTA "\n  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|\n" RESET);
    printf(MAGENTA "--+---+---+---+---+---+---+---+---+---+---+" RESET);
    for (i = 0; i < TGRILLE; i++)
    {
        printf(MAGENTA "\n%c |" RESET, 'A' + i);
        for (j = 0; j < TGRILLE; j++)
        {
            if (grille[i][j] == eau)
            {
                printf("%s", BLUE "   " MAGENTA "|" RESET);
            }
            else if (grille[i][j] == eau_touche)
            {
                printf("%s", YELLOW " * " MAGENTA "|" RESET);
            }
            else if (grille[i][j] == ID_contre_torpilleur || grille[i][j] == ID_croiseur || grille[i][j] == ID_porteAvion || grille[i][j] == ID_sous_marin || grille[i][j] == ID_torpilleur)
            {
                printf("%s", GREEN "[$]" MAGENTA "|" RESET);
            }
            else
            {
                printf("%s", RED "[$]" MAGENTA "|" RESET);
            }
        }
        printf("\n");
        printf(MAGENTA "--+---+---+---+---+---+---+---+---+---+---+" RESET);
    }
    printf("\n");
}