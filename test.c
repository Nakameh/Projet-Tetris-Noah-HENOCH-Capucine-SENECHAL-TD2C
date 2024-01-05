#include <ncurses.h>

int main() {
    // Initialiser l'environnement ncurses
    initscr();

    // Vérifier la prise en charge des couleurs
    if (has_colors() == FALSE) {
        endwin();
        printf("Votre terminal ne supporte pas les couleurs.\n");
        return 1;
    }

    // Activer les couleurs
    start_color();

    // Définir des paires de couleurs (couleur du texte et couleur de fond)
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_RED);

    // Utiliser une paire de couleurs spécifique
    attron(COLOR_PAIR(1));
    mvprintw(10, 10, "Texte rouge sur fond noir");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(12, 10, "Texte vert sur fond noir");
    attroff(COLOR_PAIR(2));

    // Mettre à jour l'écran
    refresh();

    // Attendre une saisie pour quitter
    getch();

    // Restaurer l'environnement ncurses
    endwin();

    return 0;
}