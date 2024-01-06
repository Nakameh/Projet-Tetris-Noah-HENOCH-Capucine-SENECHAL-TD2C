#pragma once
#include <stdio.h>
#include <ncurses.h>
#include "../modele/partie.h"
#include "../vue/vueNcurses.h"
#include <unistd.h>
#include <sys/time.h>
#include <time.h>


/**
 * @brief Fonction qui permet de gérer les différentes actions que l'utilisateur a à faire lors de la partie dans l'affichage ncurses
 * @param p Instance de la Classe Partie qui est le modèle du jeu Tetris
*/
void gestionControler(Partie * p);