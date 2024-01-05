#include "piece.h"
#include <time.h>



Piece * initPiece(Plateau * p) {
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

void rotationPiece(Piece * p) {
    if (!p->canRotate) return;
    Rotations * rotations = initRotations(p->idPiece);
    p->idRotation = (p->idRotation+1) % rotations->nbRotations;

    Rotation * r = rotations->tabRota[p->idRotation];
    p->hauteur = r->hauteur;
    p->largeur = r->largeur;
    p->xCoordsCentre = r->xCentre;
    p->yCoordsCentre = r->yCentre;

    for (int i = 0; i < p->hauteur * p->largeur; i++) {
        if (r->tab[i]) {
            if (!p->cases[i]) p->cases[i] = initCase();
            setOccupeCase(p->cases[i]);
            setColorCase(p->cases[i], p->color);
        }
        else {
            if (p->cases[i]) deleteCase(p->cases[i]);
            p->cases[i] = NULL;
        }
    }
    deleteRotations(rotations);
}

Piece * copyPiece(Piece * p) {
    Piece * res = (Piece *) malloc(sizeof(Piece));
    if (!res) {
        printf("[ERREUR] Erreur d'allocution dynamique d'une pièce !");
        exit(9);
    }
    res->canRotate = p->canRotate;
    res->color = p->color;
    res->hauteur = p->hauteur;
    res->idPiece = p->idPiece;
    res->idRotation = p->idRotation;
    res->largeur = p->largeur;
    res->x = p->x;
    res->xCoordsCentre = p->xCoordsCentre;
    res->y = p->y;
    res->yCoordsCentre = p->yCoordsCentre;
    res->cases = (Case **) malloc(sizeof(Case *) * res->hauteur * res->largeur);
    if (!res) {
        printf("[ERREUR] Erreur d'allocution dynamique d'une pièce !");
        exit(9);
    }
    for (int i = 0; i < res->hauteur * res->largeur; i++) {
        if (p->cases[i]) {
            res->cases[i] = initCase();
            setOccupeCase(res->cases[i]);
            setColorCase(res->cases[i], res->color);
        } else res->cases[i] = NULL;
    }
    return res;
}


Piece * initNewPiece(Plateau * p, unsigned char idp) {
    Piece * piece = (Piece *) malloc(sizeof(Piece));
    if (!piece) {
        printf("[ERREUR] Erreur d'allocution dynamique d'une pièce !");
        exit(9);
    }
    piece->idPiece = rand()%7;
    while (piece->idPiece == idp) piece->idPiece = rand()%7;
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