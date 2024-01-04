#include <stdio.h>
#include <string.h>
#include "modele/plateau.h"

//COULEURS : 0 = VIDE; 1 = JAUNE; 2 = BLEU; 3 = ROUGE; 4 = VERST 5 = ORANGE; 6 = ROSE; 7 = VIOLET


int main(int argc, char const *argv[]){
    if (argc == 1) {
        printf("Affichage ncurses\n");
    } else if (argc == 2 && strcmp("-no-gui", argv[1]) == 0) {
        printf("Affichage SDL\n");
    } else {
        printf("[ERREUR] Nombre de paramètres invalides/Paramètre invalide !\n./tetris [-no-gui]\n");
    }
    Plateau * p = initPlateau(20,10);

    Piece * piece = initPiece2(p);

    Plateau * res = plateauWithPiece(p, piece);

    printf("Affichage du tableau :\n");
    for (int i = 0; i < res->nbLigne; i++) {
        printf("|");
        for (int j = 0; j < res->nbColonne; j++) {
            if (res->tab[i * res->nbColonne + j]->occupe) printf("%d%d", res->tab[i * res->nbColonne + j]->color, res->tab[i * res->nbColonne + j]->color);
            else printf("  ");
        }
        printf("|\n");
    }

    deletePlateau(p);
    deletePlateau(res);
    deletePiece(piece);
    return 0;
}
