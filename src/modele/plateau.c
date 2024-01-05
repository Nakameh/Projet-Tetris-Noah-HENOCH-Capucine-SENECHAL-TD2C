#include "plateau.h"
#include <string.h>

Plateau * initPlateau(unsigned char nbLigne, unsigned char nbColonne) {
    Plateau* p = (Plateau *) malloc(sizeof(Plateau));
    if (!p) {
        printf("Erreur d'allocution mémoire lors de la création du plateau !\n");
        exit (22);
    }
    p->nbColonne = nbColonne;
    p->nbLigne = nbLigne;
    p->tab = (Case **) malloc(sizeof(Case*) * nbColonne * nbLigne);
    for (int i = 0; i < nbLigne * nbColonne; i++) {
            p->tab[i] = initCase();
    }
    return p;
}

void deletePlateau(Plateau * p) {
    for (int i = 0; i < p->nbColonne * p->nbLigne; i++) deleteCase(p->tab[i]);
    free(p->tab);
    free(p);
}

Plateau * copyPlateau(Plateau * src) {
    Plateau* p = (Plateau *) malloc(sizeof(Plateau));
    if (!p) {
        printf("Erreur d'allocution mémoire lors de la création du plateau !\n");
        exit (22);
    }
    p->nbColonne = src->nbColonne;
    p->nbLigne = src->nbLigne;
    p->tab = (Case **) malloc(sizeof(Case *) * p->nbColonne * p->nbLigne);
    for (int i = 0; i < p->nbColonne * p->nbLigne; i++) {
            p->tab[i] = copyCase(src->tab[i]);
    }
    return p;
}


Plateau * plateauWithPiece(Plateau * plat, Piece * piece) {
    Plateau * res = copyPlateau(plat);
    for (int i = 0; i < piece->hauteur; i++) {
        for (int j = 0; j < piece->largeur; j++) {
            if (piece->cases[i * piece->largeur + j]) {
                Case * c = res->tab[res->nbColonne * (piece->y + (i - piece->yCoordsCentre)) + (piece->x + (j - piece->xCoordsCentre))];
                setColorCase(c, piece->color);
                setOccupeCase(c);
            }
        }
    }

    return res;
}


Case * getCase(Plateau *p, int i, int j) {
    return p->tab[p->nbColonne * i + j];
}