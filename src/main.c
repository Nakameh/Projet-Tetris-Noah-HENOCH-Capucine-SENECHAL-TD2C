#include <stdio.h>
#include <string.h>
#include "modele/partie.h"
#include <time.h>

//COULEURS : 32 = VIDE; 1 = JAUNE; 2 = BLEU; 3 = ROUGE; 4 = VERST 5 = ORANGE; 6 = ROSE; 7 = VIOLET


int main(int argc, char const *argv[]){
    srand(time(NULL));
    unsigned char nbLigne = 20;
    unsigned char nbColonne = 10;
    bool gui = true;
    
    int i = 1;
    while (i < argc) {
        if (strcmp("-no-gui", argv[i]) == 0) {
            gui = false;
        } else if (strcmp("-l", argv[i]) == 0) {
            nbLigne =(unsigned char) atoi(argv[i++]);
        } else if (strcmp("-c", argv[i]) == 0) {
            nbColonne =(unsigned char) atoi(argv[i++]);
        } else {
            printf("[ERREUR] Paramètres invalides Utilisation :!\n./tetris [-no-gui] [-l nombreDeLignes] [-c nombreDeColonnes]\n");
        }
        i++;
    }

    if (!gui) {
        printf("Affichage ncurses\n");
    } else {
        printf("Affichage SDL\n");
    }
    
    
    Partie * partie = initPartie(nbLigne, nbColonne);

    Plateau * plat = plateauWithPiece(partie->plateauDeJeu, partie->piece);

    for (int i = 0; i < plat->nbLigne; i++) {
        printf("|");
        for (int j = 0; j < plat->nbColonne; j++) {
            Case * c = getCase(plat, i, j);
            if (c->occupe) printf("%d%d", c->color, c->color);
            else printf("  ");
        }
        printf("|\n");
    }    
    printf("\n\n");
    deletePlateau(plat);

    for (int k = 0; k < 25; k++) {
        prochaineEtape(partie);
        plat = plateauWithPiece(partie->plateauDeJeu, partie->piece);

        for (int i = 0; i < plat->nbLigne; i++) {
            printf("|");
            for (int j = 0; j < plat->nbColonne; j++) {
                Case * c = getCase(plat, i, j);
                if (c->occupe) printf("%d%d", c->color, c->color);
                else printf("  ");
            }
            printf("|\n");
        }    
        printf("\n\n");
        deletePlateau(plat);
    }
    deletePartie(partie);
    return 0;
}
