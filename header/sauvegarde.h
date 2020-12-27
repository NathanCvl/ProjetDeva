#ifndef SAUVEGARDE
#define SAUVEGARDE
#include <stdio.h>
#include <stdlib.h>
#include "../header/grille.h"
void SaveGrille(int grille[TGRILLE][TGRILLE], FILE *fichier, char nom[]);
#endif