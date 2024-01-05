#pragma once
#include "case.h"
typedef struct _piece Piece;
#include "piece.h"
#include <stdbool.h>

typedef struct _plateau
{
    unsigned char nbLigne;
    unsigned char nbColonne;
    Case ** tab;
} Plateau;



Plateau * initPlateau(unsigned char nbLigne, unsigned char nbColonne);

void deletePlateau(Plateau * p);

Plateau * copyPlateau(Plateau * src) ;

Plateau * plateauWithPiece(Plateau * plat, Piece * piece);

Case * getCase(Plateau *p, int i, int j);

bool peutRotatePlateau(Plateau *pl, Piece * pi);

bool peutBougerGauchePlateau(Plateau *pl, Piece * pi);

bool peutBougerDroitePlateau(Plateau *pl, Piece * pi);

bool peutTomberPlateau(Plateau *pl, Piece * pi);

void deposePiecePlateau(Plateau *pl, Piece * pi);

