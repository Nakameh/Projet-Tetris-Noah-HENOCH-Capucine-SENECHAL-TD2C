#include "rotation.h"


Rotations * initRotations(int typePiece) {
    Rotations * res = (Rotations *) malloc(sizeof(Rotations));
    if (!res) {
        printf("[ERREUR] Erreur d'allocution dynamique pour un tableau de rotations !\n");
        exit(21);
    }
    
    switch (typePiece)
    {
    case 0:
        initRotation0(res);
        break;
    
    case 1:
        initRotation1(res);
        break;

    case 2:
        initRotation2(res);
        break;

    case 3:
        initRotation3(res);
        break;

    case 4:
        initRotation4(res);
        break;

    case 5:
        initRotation5(res);
        break;

    case 6:
        initRotation6(res);
        break;

    default:
        break;
    }

    return res;
}

void initRotation0(Rotations *res) {
    res->nbRotations = 1;
    res->tabRota = (Rotation **) malloc(sizeof(Rotation *));
    if (!res->tabRota) {
        printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
        exit(3);
    }
    Rotation * r = NULL;
    unsigned char tab[1][8] = {{2, 2, 0, 0, 1, 1, 1, 1}};
    for (int i = 0; i < res->nbRotations; i++) {
        r = res->tabRota[i];
        r->largeur = tab[i][0];
        r->hauteur = tab[i][1];
        r->xCentre = tab[i][2];
        r->yCentre = tab[i][3];
        r->tab = (bool *) malloc(sizeof(bool) * r->largeur * r->hauteur);
        if (!r) {
            printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
            exit(3);
        }
        for (int j = 4; j < 4 + (r->hauteur * r->largeur); j++) r->tab[j - 4] = tab[j];
    }
}


void initRotation1(Rotations *res) {
    res->nbRotations = 4;
    res->tabRota = (Rotation **) malloc(sizeof(Rotation *));
    if (!res->tabRota) {
        printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
        exit(3);
    }
    Rotation * r = NULL;
    unsigned char tab[4][8] = {{1, 4, 0, 1, 1, 1, 1, 1}, {4, 1, 1, 0, 1, 1, 1, 1}, {1, 4, 0, 3, 1, 1, 1, 1}, {4, 1, 3, 0, 1, 1, 1, 1}};
    for (int i = 0; i < res->nbRotations; i++) {
        r = res->tabRota[i];
        r->largeur = tab[i][0];
        r->hauteur = tab[i][1];
        r->xCentre = tab[i][2];
        r->yCentre = tab[i][3];
        r->tab = (bool *) malloc(sizeof(bool) * r->largeur * r->hauteur);
        if (!r) {
            printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
            exit(3);
        }
        for (int j = 4; j < 4 + (r->hauteur * r->largeur); j++) r->tab[j - 4] = tab[j];
    }
}

void initRotation2(Rotations *res) {
    res->nbRotations = 4;
    res->tabRota = (Rotation **) malloc(sizeof(Rotation *));
    if (!res->tabRota) {
        printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
        exit(3);
    }
    Rotation * r = NULL;
    unsigned char tab[4][10] = {{3, 2, 1, 0, 0, 1, 1, 1, 1, 0}, {2, 3, 0, 1, 1, 0, 1, 1, 0, 1}, {3, 2, 1, 1, 0, 1, 1, 1, 1, 0}, {2, 3, 1, 1, 1, 0, 1, 1, 0, 1}};
    for (int i = 0; i < res->nbRotations; i++) {
        r = res->tabRota[i];
        r->largeur = tab[i][0];
        r->hauteur = tab[i][1];
        r->xCentre = tab[i][2];
        r->yCentre = tab[i][3];
        r->tab = (bool *) malloc(sizeof(bool) * r->largeur * r->hauteur);
        if (!r) {
            printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
            exit(3);
        }
        for (int j = 4; j < 4 + (r->hauteur * r->largeur); j++) r->tab[j - 4] = tab[j];
    }
}


void initRotation3(Rotations *res) {
    res->nbRotations = 4;
    res->tabRota = (Rotation **) malloc(sizeof(Rotation *));
    if (!res->tabRota) {
        printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
        exit(3);
    }
    Rotation * r = NULL;
    unsigned char tab[4][10] = {{3, 2, 1, 0, 1, 1, 0, 0, 1, 1}, {2, 3, 0, 1, 0, 1, 1, 1, 1, 0}, {3, 2, 1, 1, 1, 1, 0, 0, 1, 1}, {2, 3, 1, 1, 0, 1, 1, 1, 1, 0}};
    for (int i = 0; i < res->nbRotations; i++) {
        r = res->tabRota[i];
        r->largeur = tab[i][0];
        r->hauteur = tab[i][1];
        r->xCentre = tab[i][2];
        r->yCentre = tab[i][3];
        r->tab = (bool *) malloc(sizeof(bool) * r->largeur * r->hauteur);
        if (!r) {
            printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
            exit(3);
        }
        for (int j = 4; j < 4 + (r->hauteur * r->largeur); j++) r->tab[j - 4] = tab[j];
    }
}

void initRotation4(Rotations *res) {
    res->nbRotations = 4;
    res->tabRota = (Rotation **) malloc(sizeof(Rotation *));
    if (!res->tabRota) {
        printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
        exit(3);
    }
    Rotation * r = NULL;
    unsigned char tab[4][10] = {{2, 3, 0, 1, 1, 0, 1, 0, 1, 1}, {3, 2, 1, 1, 0, 0, 1, 1, 1, 1}, {2, 3, 1, 1, 1, 1, 0, 1, 0, 1}, {3, 2, 1, 0, 1, 1, 1, 1, 0, 0}};
    for (int i = 0; i < res->nbRotations; i++) {
        r = res->tabRota[i];
        r->largeur = tab[i][0];
        r->hauteur = tab[i][1];
        r->xCentre = tab[i][2];
        r->yCentre = tab[i][3];
        r->tab = (bool *) malloc(sizeof(bool) * r->largeur * r->hauteur);
        if (!r) {
            printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
            exit(3);
        }
        for (int j = 4; j < 4 + (r->hauteur * r->largeur); j++) r->tab[j - 4] = tab[j];
    }
}

void initRotation5(Rotations *res) {
    res->nbRotations = 4;
    res->tabRota = (Rotation **) malloc(sizeof(Rotation *));
    if (!res->tabRota) {
        printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
        exit(3);
    }
    Rotation * r = NULL;
    unsigned char tab[4][10] = {{2, 3, 1, 1, 0, 1, 0, 1, 1, 1}, {3, 2, 1, 0, 1, 1, 1, 0, 0, 1}, {2, 3, 0, 1, 1, 1, 1, 0, 1, 0}, {3, 2, 1, 1, 1, 0, 0, 1, 1, 1}};
    for (int i = 0; i < res->nbRotations; i++) {
        r = res->tabRota[i];
        r->largeur = tab[i][0];
        r->hauteur = tab[i][1];
        r->xCentre = tab[i][2];
        r->yCentre = tab[i][3];
        r->tab = (bool *) malloc(sizeof(bool) * r->largeur * r->hauteur);
        if (!r) {
            printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
            exit(3);
        }
        for (int j = 4; j < 4 + (r->hauteur * r->largeur); j++) r->tab[j - 4] = tab[j];
    }
}

void initRotation6(Rotations *res) {
    res->nbRotations = 4;
    res->tabRota = (Rotation **) malloc(sizeof(Rotation *));
    if (!res->tabRota) {
        printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
        exit(3);
    }
    Rotation * r = NULL;
    unsigned char tab[4][10] = {{3, 2, 1, 0, 1, 1, 1, 0, 1, 0}, {2, 3, 0, 1, 1, 0, 1, 1, 1, 0}, {3, 2, 1, 1, 0, 1, 0, 1, 1, 1}, {2, 3, 1, 1, 0, 1, 1, 1, 0, 1}};
    for (int i = 0; i < res->nbRotations; i++) {
        r = res->tabRota[i];
        r->largeur = tab[i][0];
        r->hauteur = tab[i][1];
        r->xCentre = tab[i][2];
        r->yCentre = tab[i][3];
        r->tab = (bool *) malloc(sizeof(bool) * r->largeur * r->hauteur);
        if (!r) {
            printf("[ERREUR] Erreur d'allocution dynamique pour une rotation !\n");
            exit(3);
        }
        for (int j = 4; j < 4 + (r->hauteur * r->largeur); j++) r->tab[j - 4] = tab[j];
    }
}


void deleteRotations(Rotations * r) {
    for (int i = 0; i < r->nbRotations; i++) free(r->tabRota[i]->tab);
    free(r->tabRota);
    free(r);
}