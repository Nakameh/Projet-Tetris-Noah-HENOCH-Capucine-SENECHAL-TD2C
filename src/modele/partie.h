#pragma once
#include "plateau.h"


typedef struct _partie
{
    long unsigned score;
    unsigned char niveau;
    Plateau * plateauDeJeu;
    Piece * piece;
} Partie;

Partie * initPartie(unsigned char ligne, unsigned char colonne);

void deletePartie(Partie * p);

char * displayPlateau(Partie * p);