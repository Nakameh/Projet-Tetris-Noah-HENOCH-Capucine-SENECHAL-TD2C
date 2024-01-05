#pragma once
typedef struct _plateau Plateau;

#include "plateau.h"

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




Piece * initPiece() ;

Piece * initPiece0(Plateau * p);


Piece * initPiece1(Plateau * p);


Piece * initPiece2(Plateau * p);


Piece * initPiece3(Plateau * p);


Piece * initPiece4(Plateau * p);

Piece * initPiece5(Plateau * p);

Piece * initPiece6(Plateau * p);

void deletePiece(Piece * p);

void tombePiece(Piece *p);

void deplacementGauchePiece(Piece * p);

void deplacementDroitePiece(Piece * p);