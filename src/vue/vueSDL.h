#pragma once
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>
#include "../modele/partie.h"
#include "../controller/sdlController.h"


/**
 * @brief Fonction qui permet d'initialiser une fenêtre SDL pour jouer à Tetris
 * @param ligne Nombre de ligne du plateau de Tetris
 * @param colonne Nombre de colonne du plateau de Tetris
*/
void createWindowSDL(unsigned char ligne, unsigned char colonne);

/**
 * @brief Fonction permettant de mettre à jour l'affichage SDL de Tetris
 * @param p Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
*/
void updateWindowSDL(Partie * p);

/**
 * @brief Fonction permettant de mettre fin à l'affichage SDL de Tetris
*/
void closeWindowSDL();