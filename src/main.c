#include <stdio.h>
#include <string.h>
#include "modele/partie.h"

//COULEURS : 32 = VIDE; 1 = JAUNE; 2 = BLEU; 3 = ROUGE; 4 = VERST 5 = ORANGE; 6 = ROSE; 7 = VIOLET


int main(int argc, char const *argv[]){
    if (argc == 1) {
        printf("Affichage ncurses\n");
    } else if (argc == 2 && strcmp("-no-gui", argv[1]) == 0) {
        printf("Affichage SDL\n");
    } else {
        printf("[ERREUR] Nombre de paramètres invalides/Paramètre invalide !\n./tetris [-no-gui]\n");
    }
    
    Partie * partie = initPartie(20, 10);
    
    displayPlateau(partie);
    
    deletePartie(partie);
    return 0;
}
