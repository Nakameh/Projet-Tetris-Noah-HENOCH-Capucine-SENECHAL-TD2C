#include "partie.h"

Partie * initPartie(unsigned char ligne, unsigned char colonne) {
    Partie* p = (Partie *) malloc(sizeof(Partie));
    if (!p) {
        printf("Erreur d'allocation de mémoire pour la partie.\n");
        exit(91);
    }
    p->niveau = 1;
    p->score = 0;
    p->plateauDeJeu = initPlateau(20, 10);
    p->piece = NULL;
    return p;
}

void deletePartie(Partie * p) {
    deletePlateau(p->plateauDeJeu);
    if (p->piece) deletePiece(p->piece);
    free(p);
}

char * displayPlateau(Partie * p) {
    Plateau * plat = NULL;
    char * res = (char *) calloc(p->plateauDeJeu->nbColonne * p->plateauDeJeu->nbLigne +1, sizeof(char));
    if (p->piece) {
        plat = plateauWithPiece(p->plateauDeJeu, p->piece);
    } else {
        plat = copyPlateau(p->plateauDeJeu);
    }

    for (int i = 0; i < plat->nbLigne; i++) {
        for (int j = 0; j < plat->nbColonne; j++) {
            Case * c = getCase(plat, i, j);
            if (c->occupe) res[i * plat->nbColonne + j] = c->color;
            else res[i * plat->nbColonne + j] = ' ';
        }
    }
    return res;
}