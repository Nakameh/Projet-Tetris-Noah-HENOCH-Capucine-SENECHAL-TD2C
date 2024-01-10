#include "./vueSDL.h"

unsigned char colors[8][3] = {{0, 0, 0}, {244, 255, 42}, {31, 226, 255}, {244, 0, 0}, {0, 255, 43}, {255, 133, 0}, {255, 58, 186}, {162, 0, 148}};

void dessineRectangle(windowManager * wm, int x, int y, int sizeX, int sizeY, unsigned char color[3]) {
    if (SDL_SetRenderDrawColor(wm->renderer, color[0], color[1], color[2], 255)) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        closeWindowSDL(wm);
        exit(EXIT_FAILURE);
    }
    if(SDL_RenderFillRect(wm->renderer, &((SDL_Rect) {x, y, x + sizeX, y + sizeY}))) {
        fprintf(stderr, "Erreur SDL_RenderFillRect : %s", SDL_GetError());
        closeWindowSDL(wm);
        exit(EXIT_FAILURE);
    }
} 


void createWindowSDL(Partie * p) {
    windowManager * wm = windowManager_init("Tetris", p->plateauDeJeu->nbColonne * 42 + 200,p->plateauDeJeu->nbLigne * 42 + 60);
    updateWindowSDL(wm, p);
    getchar();
    closeWindowSDL(wm);
}

void updateWindowSDL(windowManager * wm, Partie * p) {
    dessineRectangle(wm, 0, 0, p->plateauDeJeu->nbColonne * 42 + 200,p->plateauDeJeu->nbLigne * 42 + 60, colors[0]);
}

void closeWindowSDL(windowManager * wm) {
    windowManager_destroy(wm);
}