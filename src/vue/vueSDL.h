#pragma once
#include <stdbool.h>
#include "../modele/partie.h"
#include "../controller/sdlController.h"
#include "./windowManager.h"


/**
 * @brief Fonction qui permet d'initialiser une fenêtre SDL pour jouer à Tetris
 * @param ligne Nombre de ligne du plateau de Tetris
 * @param colonne Nombre de colonne du plateau de Tetris
*/
void createWindowSDL(Partie * p);

/**
 * @brief Fonction permettant de mettre à jour l'affichage SDL de Tetris
 * @param p Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
*/
void updateWindowSDL(windowManager * wm, Partie * p) ;
/**
 * @brief Fonction permettant de mettre fin à l'affichage SDL de Tetris
*/
void closeWindowSDL(windowManager * wm);