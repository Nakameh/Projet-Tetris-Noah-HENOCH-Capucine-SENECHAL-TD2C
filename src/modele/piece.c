#include "piece.h"
#include <time.h>



Piece * initPiece() {
    srand(time(NULL));
    Piece * piece = (Piece *) malloc(sizeof(Piece));
    if (!piece) {
        printf("[ERREUR] Erreur d'allocution dynamique d'une pièce !");
        exit(9);
    }
    // 8 = nombre de couleurs
    piece->color = rand()%(8 - 1 ) + 1;
    return piece;
}


Piece * initPiece1(Plateau * p) {
    Piece * piece = initPiece();
    piece->canRotate = false;
    piece->hauteur = 2;
    piece->largeur = 2;
    piece->xCoordsCentre = 0;
    piece->yCoordsCentre = 0;  
    piece->cases = (Case **) malloc(sizeof(Case *) * piece->hauteur * piece->largeur);
    piece->x = p->nbColonne/2;
    piece->y = 0;
    piece->cases[0] = initCase();
    piece->cases[1] = initCase();
    piece->cases[2] = initCase();
    piece->cases[3] = initCase();
    for (int i = 0; i < piece->hauteur * piece->largeur; i++) 
        if (piece->cases[i]) {
            setColorCase(piece->cases[i], piece->color);
            setOccupeCase(piece->cases[i]);
        }

    return piece;
}

Piece * initPiece2(Plateau * p) {
    Piece * piece = initPiece();
    piece->canRotate = true;
    piece->hauteur = 4;
    piece->largeur = 1;
    piece->xCoordsCentre = 0;
    piece->yCoordsCentre = 1;  
    piece->cases = (Case **) malloc(sizeof(Case *) * piece->hauteur * piece->largeur);
    piece->x = p->nbColonne/2;
    piece->y = 1;

    piece->cases[0] = initCase();
    piece->cases[1] = initCase();
    piece->cases[2] = initCase();
    piece->cases[3] = initCase();
    for (int i = 0; i < piece->hauteur * piece->largeur; i++) 
        if (piece->cases[i]) {
            setColorCase(piece->cases[i], piece->color);
            setOccupeCase(piece->cases[i]);
        }

    return piece;
}

Piece * initPiece3(Plateau * p) {
    Piece * piece = initPiece();
    piece->canRotate = true;
    piece->hauteur = 2;
    piece->largeur = 3;
    piece->xCoordsCentre = 1;
    piece->yCoordsCentre = 1;  
    piece->cases = (Case **) malloc(sizeof(Case *) * piece->hauteur * piece->largeur);
    piece->x = p->nbColonne/2;
    piece->y = 1;

    piece->cases[0] = NULL;
    piece->cases[1] = initCase();
    piece->cases[2] = initCase();
    piece->cases[3] = initCase();
    piece->cases[4] = initCase();
    piece->cases[5] = NULL;
    for (int i = 0; i < piece->hauteur * piece->largeur; i++) 
        if (piece->cases[i]) {
            setColorCase(piece->cases[i], piece->color);
            setOccupeCase(piece->cases[i]);
        }

    return piece;
}

Piece * initPiece4(Plateau * p) {
    Piece * piece = initPiece();
    piece->canRotate = true;
    piece->hauteur = 2;
    piece->largeur = 3;
    piece->xCoordsCentre = 1;
    piece->yCoordsCentre = 1;  
    piece->cases = (Case **) malloc(sizeof(Case *) * piece->hauteur * piece->largeur);
    piece->x = p->nbColonne/2;
    piece->y = 1;

    piece->cases[0] = initCase();
    piece->cases[1] = initCase();
    piece->cases[2] = NULL;
    piece->cases[3] = NULL;
    piece->cases[4] = initCase();
    piece->cases[5] = initCase();
    for (int i = 0; i < piece->hauteur * piece->largeur; i++) 
        if (piece->cases[i]) {
            setColorCase(piece->cases[i], piece->color);
            setOccupeCase(piece->cases[i]);
        }

    return piece;
}


Piece * initPiece5(Plateau * p) {
    Piece * piece = initPiece();
    piece->canRotate = true;
    piece->hauteur = 3;
    piece->largeur = 2;
    piece->xCoordsCentre = 0;
    piece->yCoordsCentre = 1;  
    piece->cases = (Case **) malloc(sizeof(Case *) * piece->hauteur * piece->largeur);
    piece->x = p->nbColonne/2;
    piece->y = 1;

    piece->cases[0] = initCase();
    piece->cases[1] = NULL;
    piece->cases[2] = initCase();
    piece->cases[3] = NULL;
    piece->cases[4] = initCase();
    piece->cases[5] = initCase();
    for (int i = 0; i < piece->hauteur * piece->largeur; i++) 
        if (piece->cases[i]) {
            setColorCase(piece->cases[i], piece->color);
            setOccupeCase(piece->cases[i]);
        }

    return piece;
}


Piece * initPiece6(Plateau * p) {
    Piece * piece = initPiece();
    piece->canRotate = true;
    piece->hauteur = 3;
    piece->largeur = 2;
    piece->xCoordsCentre = 1;
    piece->yCoordsCentre = 1;  
    piece->cases = (Case **) malloc(sizeof(Case *) * piece->hauteur * piece->largeur);
    piece->x = p->nbColonne/2;
    piece->y = 1;

    piece->cases[0] = NULL;
    piece->cases[1] = initCase();
    piece->cases[2] = NULL;
    piece->cases[3] = initCase();
    piece->cases[4] = initCase();
    piece->cases[5] = initCase();
    for (int i = 0; i < piece->hauteur * piece->largeur; i++) 
        if (piece->cases[i]) {
            setColorCase(piece->cases[i], piece->color);
            setOccupeCase(piece->cases[i]);
        }

    return piece;
}

Piece * initPiece7(Plateau * p) {
    Piece * piece = initPiece();
    piece->canRotate = true;
    piece->hauteur = 2;
    piece->largeur = 3;
    piece->xCoordsCentre = 1;
    piece->yCoordsCentre = 0;  
    piece->cases = (Case **) malloc(sizeof(Case *) * piece->hauteur * piece->largeur);
    piece->x = p->nbColonne/2;
    piece->y = 0;

    piece->cases[0] = initCase();
    piece->cases[1] = initCase();
    piece->cases[2] = initCase();
    piece->cases[3] = NULL;
    piece->cases[4] = initCase();
    piece->cases[5] = NULL;
    for (int i = 0; i < piece->hauteur * piece->largeur; i++) 
        if (piece->cases[i]) {
            setColorCase(piece->cases[i], piece->color);
            setOccupeCase(piece->cases[i]);
        }

    return piece;
}



void deletePiece(Piece * p) {
    for (int i = 0; i < p->largeur * p->hauteur; i++) if (p->cases[i]) free(p->cases[i]);
    free(p->cases);
    free(p);
}