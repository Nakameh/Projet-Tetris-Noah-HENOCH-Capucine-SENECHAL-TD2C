#include "../vue/windowManager.h"
#include "../vue/vueSDL.h"
#include <unistd.h>
#include <sys/time.h>
#include <time.h>


/**
 * @brief Fonction qui permet de gérer les différentes actions que l'utilisateur a à faire lors de la partie dans l'affichage SDL
 * @param p Instance de la Classe Partie qui est le modèle du jeu Tetris
*/
void gestionController(windowManager * wm, Partie * p);