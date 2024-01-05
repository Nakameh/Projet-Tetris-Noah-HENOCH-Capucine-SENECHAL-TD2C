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
    p->scoreProchainNiveau = 10;
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

void addScorePartie(Partie * p, unsigned long nb) {
    p->score+=nb;
    gestionDeNiveauPartie(p);
} 

void gestionDeNiveauPartie(Partie * p) {
    while (p->score >= p->scoreProchainNiveau) {
        p->niveau++;
        p->scoreProchainNiveau *= 3;
    }
}

bool deleteLignePartie(Partie * p, unsigned i) {
    for (int j = 0; j < p->plateauDeJeu->nbColonne; j++) if (!getCase(p->plateauDeJeu, i, j)->occupe) return false;
    for (int j = 0; j < p->plateauDeJeu->nbColonne; j++) {
        getCase(p->plateauDeJeu, i, j)->occupe = false;
        getCase(p->plateauDeJeu, i, j)->color = ' ';
    }
    return true;
}

void gestionLignesPartie(Partie *p) {
    int nbLigneDeleted = 0;
    for (int i = 0; i < p->plateauDeJeu->nbLigne; i++) if (deleteLignePartie(p, i)) nbLigneDeleted++;
    
}