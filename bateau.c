#include "bateau.h"
#include "jeux.h"

//ici ont initialise les points de vie du bateau et les id du bateau
//on initialise un nom de bateau pour voir afficher quel bateau on a couler
void iniBateau(Grille_j *j){
    j->contre_torpilleur.idBateau=ID_contre_torpilleur;
    j->porteAvion.idBateau = ID_porteAvion;
    j->sous_marin.idBateau = ID_sous_marin;
    j->torpilleur.idBateau = ID_torpilleur;
    j->croiseur.idBateau = ID_croiseur;

    j->porteAvion.vieBateau= t_porte_avion;
    j->sous_marin.vieBateau = t_sous_marin;
    j->torpilleur.vieBateau = t_torpilleur;
    j->croiseur.vieBateau =t_croiseur;
    j->contre_torpilleur.vieBateau=t_torpilleur;

    j->porteAvion.nom = "porte_avion";
    j->sous_marin.nom = "sous marin";
    j->torpilleur.nom = "torpilleur";
    j->croiseur.nom = "croiseur";
    j->contre_torpilleur.nom = "torpilleur";
}    

void etatBateau(Bateau t){
    if (t.vieBateau>=1)
    {
        printf("le bateau %s lui reste : %d point de vie ! ",t.nom,t.vieBateau);
    }
    else{
        printf("le bateau %s viens d'étre coulé...", t.nom);
    }
}
