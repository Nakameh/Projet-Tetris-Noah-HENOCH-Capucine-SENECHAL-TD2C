#pragma once
#include <stdio.h>
#include <stdlib.h>



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
    Rotation * tabRota;
}Rotations;