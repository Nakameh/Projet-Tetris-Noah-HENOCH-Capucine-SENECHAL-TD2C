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


unsigned int finDePartie(Partie *p) {
    for (int i = 0; i < p->plateauDeJeu->nbColonne; i++) {
        if (getCase(p, 0, i)->occupe) return true;
    }
    return false;
}