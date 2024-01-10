#include "ncursesControler.h"

void gestionControler(Partie * p) {  
    int ch;
    
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double temps = (double) time(NULL) + (double) ((double)tv.tv_usec / 1000000);



    while (1) {
        ch = getch();
        if (ch == 'q') break;
        gettimeofday(&tv, NULL);
        double tmp = (double) time(NULL) + (double) ((double)tv.tv_usec / 1000000);
        double nb = 1;
        for (int i = 1; i < p->niveau; i++) nb = nb*0.8;
        if (tmp - temps >= nb) {
            if (!prochaineEtape(p)) {
                closeWindowNcurses();
                return;  
            } 
            updateWindowNcurses(p);
            temps = tmp;
        }

        switch (ch)
        {
        case KEY_UP:
            if (peutRotatePlateau(p->plateauDeJeu, p->piece)) {
                rotationPiece(p->piece);
                updateWindowNcurses(p);
            }
            break;

        case KEY_LEFT:
            if (peutBougerGauchePlateau(p->plateauDeJeu, p->piece)) {
                deplacementGauchePiece(p->piece);
                updateWindowNcurses(p);
            }
            break;

        case KEY_RIGHT:
            if (peutBougerDroitePlateau(p->plateauDeJeu, p->piece)) {
                deplacementDroitePiece(p->piece);
                updateWindowNcurses(p);
            }
            break;

        case KEY_DOWN:
            if (!prochaineEtape(p)) {
                closeWindowNcurses();
                return;  
            } 
            updateWindowNcurses(p);
            temps = tmp;
            break;
        
        case 'r':
            closeWindowNcurses();
            createWindowSDL(p);
            return;

        default:
            break;
        }
        

    }
    closeWindowNcurses();
}