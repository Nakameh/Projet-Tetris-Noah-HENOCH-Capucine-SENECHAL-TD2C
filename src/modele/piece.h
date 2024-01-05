#pragma once
typedef struct _plateau Plateau;

#include "plateau.h"
#include "rotation.h"

typedef struct _piece
{
    unsigned char idPiece;
    unsigned char idRotation;
    unsigned canRotate : 1;
    unsigned char hauteur;
    unsigned char largeur;
    unsigned char x;
    unsigned char y;
    unsigned char color;
    unsigned char xCoordsCentre;
    unsigned char yCoordsCentre;
    Case ** cases;  
} Piece;




Piece * initPiece(Plateau * p) ;

void deletePiece(Piece * p);

void tombePiece(Piece *p);

void deplacementGauchePiece(Piece * p);

void deplacementDroitePiece(Piece * p);

void rotationPiece(Piece * p);

Piece * copyPiece(Piece * p);

Piece * initNewPiece(Plateau * p, unsigned char idp) ;