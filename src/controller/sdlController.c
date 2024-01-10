#include "sdlController.h"

void gestionController(windowManager * wm, Partie * p) {
    SDL_Event event;
    SDL_bool quit = SDL_FALSE;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double temps = (double) time(NULL) + (double) ((double)tv.tv_usec / 1000000);


    while (!quit) {
        int res = SDL_PollEvent(&event);
        double tmp = (double) time(NULL) + (double) ((double)tv.tv_usec / 1000000);
        if (!res) {
            gettimeofday(&tv, NULL);
            double nb = 1;
            for (int i = 1; i < p->niveau; i++) nb = nb*0.8;
            if (tmp - temps >= nb) {
                if (!prochaineEtape(p)) {
                    closeWindowSDL(wm);
                    quit = SDL_QUIT;
                } 
                updateWindowSDL(wm, p);
                temps = tmp;
            }
            continue;
        }
        if (event.type == SDL_QUIT) {
            closeWindowSDL(wm);
            quit = SDL_TRUE;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                if (peutRotatePlateau(p->plateauDeJeu, p->piece)) {
                    rotationPiece(p->piece);
                    updateWindowSDL(wm, p);
                }
                break;

            case SDLK_DOWN:
                if (!prochaineEtape(p)) {
                    closeWindowSDL(wm);
                    quit = SDL_TRUE;
                }
                updateWindowSDL(wm, p);
                temps = tmp;
                break;

            case SDLK_LEFT:
                if (peutBougerGauchePlateau(p->plateauDeJeu, p->piece)) {
                    deplacementGauchePiece(p->piece);
                    updateWindowSDL(wm, p);
                }
                break;

            case SDLK_RIGHT:
                if (peutBougerDroitePlateau(p->plateauDeJeu, p->piece)) {
                    deplacementDroitePiece(p->piece);
                    updateWindowSDL(wm, p);                
                }               
                break;

            case SDLK_q:
                closeWindowSDL(wm);
                quit = SDL_TRUE;
                break;
            
            default:
                break;
            }
        }
    }
}