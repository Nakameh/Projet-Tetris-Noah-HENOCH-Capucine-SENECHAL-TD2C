#include <stdio.h>
#include <string.h>
#include "modele/case.h"

int main(int argc, char const *argv[]){
    if (argc == 1) {
        printf("Affichage ncurses\n");
    } else if (argc == 2 && strcmp("-no-gui", argv[1]) == 0) {
        printf("Affichage SDL\n");
    } else {
        printf("[ERREUR] Nombre de paramètres invalides/Paramètre invalide !\n./tetris [-no-gui]\n");
    }
    return 0;
}
