#ifndef _COORDONNEES_
#define _COORDONNEES_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/* definiton d'une structure coordonnees pour pour stocker la direction et les coordonnees dans une seule variable*/
typedef struct{
    int x, y;
    char placement; /* pour definir la direction du bateau sur la grille */
} Coordonnees;
Coordonnees *caracToCdn(char cdn[]);

#endif