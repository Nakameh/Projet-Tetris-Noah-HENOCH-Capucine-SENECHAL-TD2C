#include "./vueSDL.h"

unsigned char colors[8][3] = {{0, 0, 0}, {244, 255, 42}, {31, 226, 255}, {244, 0, 0}, {0, 255, 43}, {255, 133, 0}, {255, 58, 186}, {162, 0, 148}};

void dessineRectangle(windowManager * wm, int x1, int y1, int x2, int y2, unsigned char color[3]) {
    if (!wm->renderer) return;
    if (SDL_SetRenderDrawColor(wm->renderer, color[0], color[1], color[2], 255)) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        closeWindowSDL(wm);
        exit(EXIT_FAILURE);
    }
    if(SDL_RenderFillRect(wm->renderer, &((SDL_Rect) {x1, y1, x2, y2}))) {
        fprintf(stderr, "Erreur SDL_RenderFillRect : %s", SDL_GetError());
        closeWindowSDL(wm);
        exit(EXIT_FAILURE);
    }
} 

void dessineLigneBlanche(windowManager * wm, int x1, int y1, int x2, int y2) {
    if (!wm->renderer) return;
    if (SDL_SetRenderDrawColor(wm->renderer, 255, 255, 255, 255)) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        closeWindowSDL(wm);
        exit(EXIT_FAILURE);
    }
    if(SDL_RenderDrawLine(wm->renderer, x1, y1, x2, y2)) {
        fprintf(stderr, "Erreur SDL_RenderDrawLine : %s", SDL_GetError());
        closeWindowSDL(wm);
        exit(EXIT_FAILURE);
    }
}


void createWindowSDL(Partie * p) {
    windowManager * wm = windowManager_init("Tetris", p->plateauDeJeu->nbColonne * 32 + 240,p->plateauDeJeu->nbLigne * 32 + 130);
    updateWindowSDL(wm, p);
    gestionController(wm, p);
}





void updateWindowSDL(windowManager * wm, Partie * p) {
    if (!wm->renderer) return;
    SDL_RenderClear(wm->renderer);
    dessineRectangle(wm, 0, 0, p->plateauDeJeu->nbColonne * 32 + 240, p->plateauDeJeu->nbLigne * 32 + 130, colors[0]);
    dessineLigneBlanche(wm, 29, 99, 29, p->plateauDeJeu->nbLigne * 32 + 100);
    dessineLigneBlanche(wm, 29, 99, p->plateauDeJeu->nbColonne * 32 + 30, 99);
    dessineLigneBlanche(wm, p->plateauDeJeu->nbColonne * 32 + 30, 99, p->plateauDeJeu->nbColonne * 32 + 30, p->plateauDeJeu->nbLigne * 32 + 100);
    dessineLigneBlanche(wm, 29, p->plateauDeJeu->nbLigne * 32 + 100, p->plateauDeJeu->nbColonne * 32 + 30, p->plateauDeJeu->nbLigne * 32 + 100);

    TTF_Font* font = TTF_OpenFont("./assets/arial.ttf", 16);
    SDL_Color textColor = {255, 255, 255}; // Couleur du texte (R, G, B)

    if (!font) {
        fprintf(stderr, "Erreur lors de l'ouverture de la police : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }   
    
    char text1[100]; 
    sprintf(text1, "Niveau : %u ('Fleche haut': rotation) (Fleche bas: descendre)", p->niveau);

    char text2[150];
    sprintf(text2, "Score : %lu ('Fleche gauche/droite' deplacer vers gauche/droite)", p->score);
    
    SDL_Surface* textSurface1 = TTF_RenderText_Solid(font, "Tetris !  ('q': quitter) ('r': Vue Ncurses)", textColor);
    SDL_Surface* textSurface2 = TTF_RenderText_Solid(font, text1, textColor);
    SDL_Surface* textSurface3 = TTF_RenderText_Solid(font, text2, textColor);
    
    SDL_Texture* textTexture1 = SDL_CreateTextureFromSurface(wm->renderer, textSurface1);
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(wm->renderer, textSurface2);
    SDL_Texture* textTexture3 = SDL_CreateTextureFromSurface(wm->renderer, textSurface3);
    
    SDL_Rect textRect1 = {30, 10, textSurface1->w, textSurface1->h};
    SDL_Rect textRect2 = {30, 40, textSurface2->w, textSurface2->h};
    SDL_Rect textRect3 = {30, 80, textSurface3->w, textSurface3->h};

    SDL_RenderCopy(wm->renderer, textTexture1, NULL, &textRect1);
    SDL_RenderCopy(wm->renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(wm->renderer, textTexture3, NULL, &textRect3);

    Plateau * plat = plateauWithPiece(p->plateauDeJeu, p->piece);
    for (int ligne = 0; ligne < p->plateauDeJeu->nbLigne; ligne ++) {
        for (int colonne = 0; colonne < p->plateauDeJeu->nbColonne; colonne++) {
            Case * c = getCase(plat, ligne, colonne);
            if (c->occupe) {
                dessineRectangle(wm, colonne * 32 + 30, ligne * 32 + 100, 32, 32, colors[c->color]);
            }
        }
    }
    SDL_RenderPresent(wm->renderer);

    deletePlateau(plat);
    
    TTF_CloseFont(font);
    SDL_DestroyTexture(textTexture1);
    SDL_FreeSurface(textSurface1);
    SDL_DestroyTexture(textTexture2);
    SDL_FreeSurface(textSurface2);
    SDL_DestroyTexture(textTexture3);
    SDL_FreeSurface(textSurface3);
    
}

void closeWindowSDL(windowManager * wm) {
    windowManager_destroy(wm);
}