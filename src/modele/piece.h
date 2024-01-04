#pragma once
typedef struct _plateau Plateau;

#include "plateau.h"

typedef struct _piece
{
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