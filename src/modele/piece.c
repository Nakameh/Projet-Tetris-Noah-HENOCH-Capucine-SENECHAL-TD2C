#include "piece.h"
#include <time.h>



Piece * initPiece(Plateau * p) {
    srand(time(NULL));
    Piece * piece = (Piece *) malloc(sizeof(Piece));
    if (!piece) {
        printf("[ERREUR] Erreur d'allocution dynamique d'une pièce !");
        exit(9);
    }
    piece->idPiece = rand()%7;
    piece->idRotation = 0;
    if (piece->idPiece == 0) piece->canRotate = false;
    else piece->canRotate = true;

    // 8 = nombre de couleurs
    piece->color = rand()%(8 - 1 ) + 1;

    Rotations * rotations = initRotations(piece->idPiece);
    Rotation * r = rotations->tabRota[piece->idRotation];
    piece->hauteur = r->hauteur;
    piece->largeur = r->largeur;
    piece->xCoordsCentre = r->xCentre;
    piece->yCoordsCentre = r->yCentre;
    piece->x = p->nbColonne/2 - piece->xCoordsCentre;
    piece->y = piece->yCoordsCentre;

    piece->cases = (Case **) malloc(sizeof(Case *) * piece->hauteur * piece->largeur);
    if (!piece->cases) {
        printf("[ERREUR] Erreur d'allocution dynamique d'une pièce !");
        exit(9);
    }

    for (int i = 0; i < piece->hauteur * piece->largeur; i++) {
        if (r->tab[i]) {
            piece->cases[i] = initCase();
            setOccupeCase(piece->cases[i]);
            setColorCase(piece->cases[i], piece->color);
        }
        else piece->cases[i] = NULL;
    }
    deleteRotations(rotations);
    return piece;
}




void deletePiece(Piece * p) {
    for (int i = 0; i < p->largeur * p->hauteur; i++) if (p->cases[i]) free(p->cases[i]);
    free(p->cases);
    free(p);
}


void tombePiece(Piece *p) {
    (p->y)++;
}

void deplacementGauchePiece(Piece * p){
    p->x--;
}

void deplacementDroitePiece(Piece * p) {
    p->x++;
}