#include "joueur.h"
#include <stdio.h>
#include <stdlib.h>

/* Ryan */

typedef struct {
    char *pseudo; 
} joueur; 

void pseudo() {
    char pseudo[10]; 
    printf("Quel est votre pseudo ?\n"); 
    scanf("%s", pseudo); 
    printf ("Vous jouez sous le pseudo de : %s ! \n \n ", pseudo); 
}


