#include "case.h"


Case * initCase(){
    Case * c = (Case *) malloc(sizeof(Case));
    if (!c) {
        printf("[ERREUR] Erreur d'allocution dynamique pour une Case !\n");
        exit(7);
    }
    c->occupe = false;
    c->color = ' ';
    return c;
}

void setOccupeCase(Case * c) {
    c->occupe = true;
}

void setLibereCase(Case * c) {
    c->occupe = false;
    c->color = ' ';
}

void setColorCase(Case * c, unsigned char color) {
    c->color = color;
}

char getColorCase(Case * c) {
    return c->color;
}

unsigned isOccupedCase(Case *c) {
    return c->occupe == true;
}

void deleteCase(Case * c) {
    free(c);
}

Case * copyCase(Case * src) {
    Case * c = (Case *) malloc(sizeof(Case));
    if (!c) {
        printf("[ERREUR] Erreur d'allocution dynamique pour une Case !\n");
        exit(7);
    }
    c->occupe = src->occupe;
    c->color = src->color;
    return c;
}