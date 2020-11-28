#include "jeux.h"
/*TODO: placer  bateau avec orientation 
* afficher grille avec coordonnées
* placer bateau énémie par joueur ou IA
* attaque joueur et/ou IA
*/

/* 
*initialise la grille avec de l'eau partout donc une valeur égale à 0.
*/
Grille initaliser_grille(Grille h)
{
    int i, j;
    for (i = 0; i < TGRILLE; i++)
    {
        for (j = 0; j < TGRILLE; j++)
        {
            h.grille1[i][j]=eau;
            h.grille2[i][j]=eau;
        }
    }
    return h;
}

/*  
    
    ↑(y)
    |
    |
    |
    ------>(x)
     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 
    A|
    B|
    C|
    D|
    E|
    F|
    G|
    H|
    I|
    J|
ici on veut recuper un type coordonnées donnant pour pour coordonnées par exemple A10 et Vertical
ici la démarche et de pouvoir convertire le type string en type coordonnées


*/

Coordonnees caracToCdn(char cdn[]){
    Coordonnees coord;
    int i;
    char buffer[4];
// la direction devra être rentré en dernier on la récuper en récuperant la dernier case du tableau cdn
    coord.placement=cdn[strlen(cdn)-1];
// comme on demande d'abord la coordonnée y on récupere y en premier
// ici avec le code ASCII on convertie le caractère donc si coord.y = A on fais 'A'-'A'= 0 
    coord.y=cdn[0]-'A';

// ici on veut convertir deux caractere en nombre que le caractere '10' devienne le nombre 10
// pour pouvoir convertir les deux caractere on dois l'envoyer dans un autre tableau sans le premier et dernier caractere
// copie cdn vers buffer pour isolé la coordonnée x.
    for ( i = 0; i < strlen(cdn)-2; i++)
    {
        buffer[i]=cdn[i+1];
    }
    buffer[i+1]='\0';
//atoi() convertie des caractere alphanumérique en int mais comme le tableau commence en 0 on enleve 1 au résultat
    coord.x=atoi(buffer)-1;


    return coord;

}

void afficherGrille(int g[TGRILLE][TGRILLE])
{
    int i, j;
    printf("\n  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|");
    printf(LIGNE);
    for (i = 0; i < TGRILLE; i++)
    {
        printf("%c |", i + 'A');
        for (j = 0; j < TGRILLE; j++)
        {
            if (g[i][j] == eau){
    
             printf("%s", EAU);
            }
            else if (g[i][j] == eau_touche){
                printf("%s", EAU_T);
            }
   
        }
        printf("\n");
        printf(LIGNE);
    }
}

int main(int argc, char const *argv[])
{
    char test[10] = "J10v";
    Coordonnees c;
    Grille p;
    p=initaliser_grille(p);
    afficherGrille(p.grille1);

    return 0;
}
