#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct _rotation
{
    unsigned char hauteur;
    unsigned char largeur;
    unsigned char xCentre;
    unsigned char yCentre;
    bool * tab;
}Rotation;


typedef struct _rotations
{
    unsigned char nbRotations;
    Rotation ** tabRota;
}Rotations;

Rotations * initRotations(int typePiece) ;
void deleteRotations(Rotations * r);