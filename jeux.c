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

Coordonnees CaracToCdn(char cdn[]){
    Coordonnees coord;
    char buffer[4];
// la direction devra être rentré en dernier on la récuper en récuperant la dernier case du tableau cdn
    coord.placement=cdn[strlen(cdn)-1];
// comme on demande d'abord la coordonnée y on récupere y en premier
// ici avec le code ASCII on convertie le caractère donc si coord.y = A on fais 'A'-'A'= 0 
    coord.y=cdn[0]-'A';




    return coord;

}



int main(int argc, char const *argv[])
{  
    char string[10];
    Coordonnees c;
    Grille p;
    p=initaliser_grille(p);

    return 0;
}
