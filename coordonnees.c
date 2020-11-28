#include "coordonnees.h"
/**
    
    ↑(y)
    |
    |
    |
    ------>(x)
ici on veut recuper un type coordonnées donnant pour pour coordonnées par exmple 
entré cdn="J10V" retourne coord.x= 9 coord.y=9 et coord.placement = V
ici la démarche et de pouvoir convertire le type string en type coordonnées


*/
//retourne le type coordonnees avec comme valeur d'entrée une chaine de caractères
Coordonnees caracToCdn(char cdn[])
{
    Coordonnees coord;
    int i;
    char buffer[3];
 

    // ici on veut convertir deux caractere en nombre que le caractere '10' devienne le nombre 10
    // pour pouvoir convertir les deux caractere on dois l'envoyer dans un autre tableau sans le premier et dernier caractere
    // copie cdn vers buffer pour isolé la coordonnée x.

    for (i = 0; i < strlen(cdn) - 1; i++)
    {
        buffer[i] = cdn[i + 1];
    }
    //atoi() convertie des caractere alphanumérique en int mais comme le tableau commence en 0 on enleve 1 au résultat
    //obli
    coord.x = atoi(buffer);


    // comme on demande d'abord la coordonnée y on récupere en début du tableau
    // ici avec le code ASCII on convertie le caractère donc si coord.y = A on fais 'A'-'A'= 0
    coord.y = cdn[0] - 'A';
    // la direction devra être rentré en dernier on la récuper en récuperant la dernier case du tableau cdn
    coord.placement = cdn[strlen(cdn) - 1];
    return coord;
}
