#pragma once
#include "case.h"

typedef struct _plateau
{
    unsigned char nbLigne;
    unsigned char nbColonne;
    Case ** tab;
} Plateau;

#include "piece.h"


Plateau * initPlateau(unsigned char nbLigne, unsigned char nbColonne);

void deletePlateau(Plateau * p);

Plateau * copyPlateau(Plateau * src) ;

//Faire la fonction qui renvoie un nouveau tableau avec une pièce dedans