#include "piece.h"
#include <time.h>

Piece * initPiece(Plateau * p) {
    srand(time(NULL));
    Piece * piece = (Piece *) malloc(sizeof(Piece));
    if (!piece) {
        printf("[ERREUR] Erreur d'allocution dynamique d'une pièce !");
        return 9;
    }
    piece->x = p->nbColonne/2;
    piece->y = 1;
    return piece;

}