#ifndef _COORDONNEES_
#define _COORDONNEES_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/* définiton d'une structure coordonnees pour pour stocker la direction et les coordonnées dans une seul variable*/
typedef struct{
    int x, y;
    char placement; /* pour définir la direction du bateau sur la grille */
} Coordonnees;
Coordonnees *caracToCdn(char cdn[]);

#endif