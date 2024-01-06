#include <stdio.h>
#include <string.h>
#include <time.h>
#include "vue/vueNcurses.h"

//COULEURS : 32 = VIDE; 1 = JAUNE; 2 = BLEU; 3 = ROUGE; 4 = VERT 5 = BLANC; 6 = MAGENTA; 7 = CYAN


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

    if (nbLigne < 7) {
        printf("[ERREUR] Nombre de lignes insuffisantes (7 minimum)\n");
        exit (31);
    }

    if (nbColonne < 7) {
        printf("[ERREUR] Nombre de colonnes insuffisantes (7 minimum)\n");
        exit (11);
    }

    if (!gui) {
        createWindowNcurses(nbLigne, nbColonne);
    } else {
        printf("Affichage SDL\n");
    }
    

    return 0;
}
