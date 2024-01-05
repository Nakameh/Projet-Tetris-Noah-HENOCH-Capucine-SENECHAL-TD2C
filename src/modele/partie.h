#pragma once
#include "plateau.h"

typedef struct _partie
{
    long unsigned score;
    long unsigned scoreProchainNiveau;
    unsigned char niveau;
    Plateau * plateauDeJeu;
    Piece * piece;
} Partie;

Partie * initPartie(unsigned char ligne, unsigned char colonne);

void deletePartie(Partie * p);

unsigned finDePartie(Partie *p);

void addScorePartie(Partie * p, unsigned long nb);

void gestionDeNiveauPartie(Partie * p);

bool deleteLignePartie(Partie * p, unsigned i);

void gestionLignesPartie(Partie *p);

void ligneTombePartie(Partie * p, unsigned i);

void addPiecePartie(Partie *p) ;

void prochaineEtape(Partie * p);