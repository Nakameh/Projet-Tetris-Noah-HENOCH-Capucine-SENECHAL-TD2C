#pragma once
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../controler/ncursesControler.h"

/**
 * @brief Fonction qui permet d'initialiser une fenêtre ncurses pour jouer à Tetris
 * @param ligne Nombre de ligne du plateau de Tetris
 * @param colonne Nombre de colonne du plateau de Tetris
*/
void createWindowNcurses(unsigned char ligne, unsigned char colonne);

/**
 * @brief Fonction permettant de mettre à jour l'affichage ncurses de Tetris
 * @param p Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
*/
void updateWindowNcurses(Partie * p);

/**
 * @brief Fonction permettant de mettre fin à l'affichage ncurses de Tetris
*/
void closeWindowNcurses();