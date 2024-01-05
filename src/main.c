#include <stdio.h>
#include <string.h>
#include "modele/partie.h"

//COULEURS : 32 = VIDE; 1 = JAUNE; 2 = BLEU; 3 = ROUGE; 4 = VERST 5 = ORANGE; 6 = ROSE; 7 = VIOLET


int main(int argc, char const *argv[]){
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
        printf("[ERREUR] Nombre de paramètres invalides/Paramètre invalide !\n./tetris [-no-gui]\n");
    
    
    Partie * partie = initPartie(nbLigne, nbColonne);
        
    deletePartie(partie);
    return 0;
}
