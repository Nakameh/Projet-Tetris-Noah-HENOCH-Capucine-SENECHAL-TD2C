#include "vueNcurses.h"

unsigned char min(unsigned char nb1, unsigned char nb2) {
    if (nb1 < nb2) return nb1;
    return nb2;
}

void createWindowNcurses(unsigned char ligne, unsigned char colonne) {

    setlocale(LC_ALL, "");

    // Initialiser l'environnement ncurses
    initscr();

    scrollok(stdscr, TRUE);

    int r, c;
    getmaxyx(stdscr, r, c);

    r-= 6;
    c-=6;

    

    if ((unsigned char) r != ligne) {
        ligne = min(ligne, (unsigned char) r);
        if (ligne == (unsigned char) r) printf("[INFORMATION] Le nombre de ligne du plateau a été réduite dû aux proportions de votre terminal.\n");
    }
    if ((unsigned char) c != colonne) {
        colonne = min(colonne, (unsigned char) c);
        if (colonne == (unsigned char) c) printf("[INFORMATION] Le nombre de colonne  du plateau a été réduite dû aux proportions de votre terminal.\n");
    }



    if (ligne < 7) {
        printf("[ERREUR] Nombre de lignes insuffisantes (7 minimum)\n");
        exit (31);
    }

    if (colonne < 7) {
        printf("[ERREUR] Nombre de colonnes insuffisantes (7 minimum)\n");
        exit (11);
    }

    Partie * p = initPartie(ligne, colonne);

    if (has_colors() == true) {
        start_color();
        init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(2, COLOR_BLUE, COLOR_BLUE);
        init_pair(3, COLOR_RED, COLOR_RED);
        init_pair(4, COLOR_GREEN, COLOR_GREEN);
        init_pair(5, COLOR_WHITE, COLOR_WHITE);
        init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
        init_pair(7, COLOR_CYAN, COLOR_CYAN);
        init_pair(8, COLOR_BLACK, COLOR_BLACK);
    }


    // Désactiver l'affichage de la saisie clavier
    cbreak();

    // Désactiver la mise en mémoire tampon de la saisie clavier
    noecho();
    
    updateWindowNcurses(p);

    //temporaire
    closeWindowNcurses();

    deletePartie(p);
}

void updateWindowNcurses(Partie * p) {
    clear();
    mvprintw(0, 4, "Tetris !");
    mvprintw(1, 4, "Niveau : %u", p->niveau);
    mvprintw(2, 4, "Score : %lu", p->score);
    Plateau * plat = plateauWithPiece(p->plateauDeJeu, p->piece);
    for (int i = 0; i < plat->nbColonne * 2+2; i++) mvaddstr(4, 4 + i, "\xe2\x80\x95");
    for (int i = 0; i < plat->nbLigne; i++) {
        mvprintw(i+5, 4, "|");
        for (int j = 0; j < plat->nbColonne; j++) {
            Case * c = getCase(plat, i, j);
            if (c->occupe) {
                if (has_colors() == true) {
                    attron(COLOR_PAIR(c->color));
                    mvprintw(i+5, j * 2 +5, " ");
                    mvprintw(i+5, j * 2 +6, " ");
                    attroff(COLOR_PAIR(c->color));
                } else {
                    mvprintw(i + 5, j * 2 + 5, "%d", c->color);
                    mvprintw(i + 5, j * 2 + 6, "%d", c->color);
                }
            }
        }
        mvprintw(i+5, 5+plat->nbColonne * 2, "|");
    }
    for (int i = 0; i < plat->nbColonne * 2+2; i++) mvaddstr(plat->nbLigne + 5, 4 + i, "\xe2\x80\x95");
    deletePlateau(plat);
    refresh();
}

void closeWindowNcurses() {
    getch();
    endwin();
}