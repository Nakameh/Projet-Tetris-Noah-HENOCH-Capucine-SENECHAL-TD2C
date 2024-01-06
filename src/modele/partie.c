#include "partie.h"

Partie * initPartie(unsigned char ligne, unsigned char colonne) {
    Partie* p = (Partie *) malloc(sizeof(Partie));
    if (!p) {
        printf("Erreur d'allocation de mémoire pour la partie.\n");
        exit(91);
    }
    p->niveau = 1;
    p->score = 0;
    p->plateauDeJeu = initPlateau(ligne, colonne);
    p->piece = NULL;
    p->scoreProchainNiveau = 200;
    p->piece = initPiece(p->plateauDeJeu);
    return p;
}

void deletePartie(Partie * p) {
    deletePlateau(p->plateauDeJeu);
    if (p->piece) deletePiece(p->piece);
    free(p);
}


unsigned int finDePartie(Partie *p) {
    for (int i = 0; i < p->plateauDeJeu->nbColonne; i++) {
        if (getCase(p->plateauDeJeu, 0, i)->occupe) return true;
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
        p->scoreProchainNiveau += 200;
    }
}

void ligneTombePartie(Partie * p, unsigned i) {
    if (i > 0) {
        for (int j = 0; j < p->plateauDeJeu->nbColonne; j++) {
            Case * c1 = getCase(p->plateauDeJeu, i, j);
            Case * c2 = getCase(p->plateauDeJeu, i - 1, j);
            c1->color = c2->color;
            c1->occupe = c2->occupe;
            c2->color = ' ';
            c2->occupe = false;
        }
        ligneTombePartie(p, i-1);
    }
}

bool deleteLignePartie(Partie * p, unsigned i) {
    for (int j = 0; j < p->plateauDeJeu->nbColonne; j++) if (!getCase(p->plateauDeJeu, i, j)->occupe) return false;
    for (int j = 0; j < p->plateauDeJeu->nbColonne; j++) {
        getCase(p->plateauDeJeu, i, j)->occupe = false;
        getCase(p->plateauDeJeu, i, j)->color = ' ';
    }
    ligneTombePartie(p, i);
    return true;
}

void gestionLignesPartie(Partie *p) {
    long unsigned nbLigneDeleted = 0;
    for (int i = 0; i < p->plateauDeJeu->nbLigne; i++) if (deleteLignePartie(p, i)) nbLigneDeleted++;
    nbLigneDeleted *= 1.75;
    addScorePartie(p, nbLigneDeleted * 100);
}

void addPiecePartie(Partie *p) {
    unsigned char idp = p->piece->idPiece;
    deletePiece(p->piece);
    p->piece = initNewPiece(p->plateauDeJeu, idp);
    
}

bool prochaineEtape(Partie * p) {
    if (peutTomberPlateau(p->plateauDeJeu, p->piece)) {
        tombePiece(p->piece);
    } else {
        deposePiecePlateau(p->plateauDeJeu, p->piece);
        gestionLignesPartie(p);
        if (finDePartie(p)) return false;
        addPiecePartie(p);
    }
    return true;
}