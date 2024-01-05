#include "plateau.h"
#include <string.h>

Plateau * initPlateau(unsigned char nbLigne, unsigned char nbColonne) {
    Plateau* p = (Plateau *) malloc(sizeof(Plateau));
    if (!p) {
        printf("Erreur d'allocution mémoire lors de la création du plateau !\n");
        exit (22);
    }
    p->nbColonne = nbColonne;
    p->nbLigne = nbLigne;
    p->tab = (Case **) malloc(sizeof(Case*) * nbColonne * nbLigne);
    for (int i = 0; i < nbLigne * nbColonne; i++) {
            p->tab[i] = initCase();
    }
    return p;
}

void deletePlateau(Plateau * p) {
    for (int i = 0; i < p->nbColonne * p->nbLigne; i++) deleteCase(p->tab[i]);
    free(p->tab);
    free(p);
}

Plateau * copyPlateau(Plateau * src) {
    Plateau* p = (Plateau *) malloc(sizeof(Plateau));
    if (!p) {
        printf("Erreur d'allocution mémoire lors de la création du plateau !\n");
        exit (22);
    }
    p->nbColonne = src->nbColonne;
    p->nbLigne = src->nbLigne;
    p->tab = (Case **) malloc(sizeof(Case *) * p->nbColonne * p->nbLigne);
    for (int i = 0; i < p->nbColonne * p->nbLigne; i++) {
            p->tab[i] = copyCase(src->tab[i]);
    }
    return p;
}


Plateau * plateauWithPiece(Plateau * plat, Piece * piece) {
    Plateau * res = copyPlateau(plat);
    for (int i = 0; i < piece->hauteur; i++) {
        for (int j = 0; j < piece->largeur; j++) {
            if (piece->cases[i * piece->largeur + j]) {
                Case * c = res->tab[res->nbColonne * (piece->y + (i - piece->yCoordsCentre)) + (piece->x + (j - piece->xCoordsCentre))];
                setColorCase(c, piece->color);
                setOccupeCase(c);
            }
        }
    }

    return res;
}


Case * getCase(Plateau *p, int i, int j) {
    return p->tab[p->nbColonne * i + j];
}

bool peutRotatePlateau(Plateau *pl, Piece * pi) {
    if (!pi->canRotate) return false;
    Piece * newPiece = copyPiece(pi);
    rotationPiece(newPiece);
    for (int i = 0; i < newPiece->hauteur; i++) {
        for (int j = 0; j < newPiece->largeur; j++) {
            if (newPiece->cases[i * newPiece->largeur + j]) {
                unsigned char y = newPiece->y + (i - newPiece->yCoordsCentre);
                unsigned char x = newPiece->x + (j - newPiece->xCoordsCentre);
                if (x >= 0 && x < pl->nbColonne && y >= 0 && y < pl->nbLigne) {
                    Case * c = getCase(pl, y, x);
                    if (c->occupe) {
                        deletePiece(newPiece);
                        return false;
                    }
                } else {
                    deletePiece(newPiece);
                    return false;
                }
            }
        }
    }

    deletePiece(newPiece);
    return true;
}

bool peutBougerGauchePlateau(Plateau *pl, Piece * pi) {
    Piece * newPiece = copyPiece(pi);
    deplacementGauchePiece(newPiece);
    for (int i = 0; i < newPiece->hauteur; i++) {
        for (int j = 0; j < newPiece->largeur; j++) {
            if (newPiece->cases[i * newPiece->largeur + j]) {
                unsigned char y = newPiece->y + (i - newPiece->yCoordsCentre);
                unsigned char x = newPiece->x + (j - newPiece->xCoordsCentre);
                if (x >= 0 && x < pl->nbColonne && y >= 0 && y < pl->nbLigne) {
                    Case * c = getCase(pl, y, x);
                    if (c->occupe) {
                        deletePiece(newPiece);
                        return false;
                    }
                } else {
                    deletePiece(newPiece);
                    return false;
                }
            }
        }
    }

    deletePiece(newPiece);
    return true;
}

bool peutBougerDroitePlateau(Plateau *pl, Piece * pi) {
    Piece * newPiece = copyPiece(pi);
    deplacementDroitePiece(newPiece);
    for (int i = 0; i < newPiece->hauteur; i++) {
        for (int j = 0; j < newPiece->largeur; j++) {
            if (newPiece->cases[i * newPiece->largeur + j]) {
                unsigned char y = newPiece->y + (i - newPiece->yCoordsCentre);
                unsigned char x = newPiece->x + (j - newPiece->xCoordsCentre);
                if (x >= 0 && x < pl->nbColonne && y >= 0 && y < pl->nbLigne) {
                    Case * c = getCase(pl, y, x);
                    if (c->occupe) {
                        deletePiece(newPiece);
                        return false;
                    }
                } else {
                    deletePiece(newPiece);
                    return false;
                }
            }
        }
    }

    deletePiece(newPiece);
    return true;
}

bool peutTomberPlateau(Plateau *pl, Piece * pi) {
    Piece * newPiece = copyPiece(pi);
    tombePiece(newPiece);
    for (int i = 0; i < newPiece->hauteur; i++) {
        for (int j = 0; j < newPiece->largeur; j++) {
            if (newPiece->cases[i * newPiece->largeur + j]) {
                unsigned char y = newPiece->y + (i - newPiece->yCoordsCentre);
                unsigned char x = newPiece->x + (j - newPiece->xCoordsCentre);
                if (x >= 0 && x < pl->nbColonne && y >= 0 && y < pl->nbLigne) {
                    Case * c = getCase(pl, y, x);
                    if (c->occupe) {
                        deletePiece(newPiece);
                        return false;
                    }
                } else {
                    deletePiece(newPiece);
                    return false;
                }
            }
        }
    }

    deletePiece(newPiece);
    return true;
}

void deposePiecePlateau(Plateau *pl, Piece * pi) {
    for (int i = 0; i < pi->hauteur; i++) {
        for (int j = 0; j < pi->largeur; j++) {
            if (pi->cases[i * pi->largeur + j]) {
                unsigned char y = pi->y + (i - pi->yCoordsCentre);
                unsigned char x = pi->x + (j - pi->xCoordsCentre);
                if (x >= 0 && x < pl->nbColonne && y >= 0 && y < pl->nbLigne) {
                    Case * c = getCase(pl, y, x);
                    setOccupeCase(c);
                    setColorCase(c, pi->color);
                }
            }
        }
    }
}

