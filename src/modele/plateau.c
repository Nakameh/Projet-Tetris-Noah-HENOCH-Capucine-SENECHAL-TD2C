#include "plateau.h"

Plateau * initPlateau(unsigned char nbLigne, unsigned char nbColonne) {
    Plateau* p = (Plateau *) malloc(sizeof(Plateau));
    if (!p) {
        printf("Erreur d'allocution mémoire lors de la création du plateau !\n");
        exit (22);
    }
    p->nbColonne = nbColonne;
    p->nbLigne = nbLigne;
    p->tab = (Case **) malloc(sizeof(Case) * nbColonne * nbLigne);
    for (int i = 0; i < nbLigne * nbColonne; i++) {
            p->tab[i] = initCase();
    }
}

void deletePlateau(Plateau * p) {
    for (int i = 0; i < p->nbColonne * p->nbLigne; i++) deleteCase(p->tab[i]);
    free(p->tab);
    free(p);
}