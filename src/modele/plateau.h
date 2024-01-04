#pragma once
#include "case.h"
typedef struct _piece Piece;
#include "piece.h"

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
