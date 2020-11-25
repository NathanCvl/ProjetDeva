#include "joueur.h"
#include <stdio.h>
#include <stdlib.h>

/* Ryan */

typedef struct {
    char pseudo[40]; 
} joueur; 

joueur pseudo() {
    joueur j;
    printf("Quel est votre pseudo ?\n"); 
    scanf("%s", j.pseudo); 
    return j;
}
int main(int argc, char const *argv[])
{
    joueur j;
    
    j=pseudo();
    printf("%s",j.pseudo);
    return 0;
}


