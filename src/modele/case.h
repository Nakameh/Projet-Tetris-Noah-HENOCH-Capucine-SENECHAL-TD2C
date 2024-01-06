#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * @brief Classe représentant une case du plateau de jeu Tetris
*/
typedef struct _case {
    unsigned occupe : 1;
    unsigned char color;
} Case;

/**
 * @brief Fonction permettant de créer un pointeur d'une instance de la classe Case représentant une case du plateau de jeu Tetris
 * @return Un pointeur d'une instance de la classe Case représentant une case du plateau de jeu Tetris
*/
Case * initCase();

/**
 * @brief Fonction qui permet d'occuper une case du plateau de jeu
 * @param c Un pointeur d'une instance de la classe Case représentant une case du plateau de jeu Tetris
*/
void setOccupeCase(Case * c);


/**
 * @brief Fonction qui permet de libérer une case du plateau de jeu
 * @param c Un pointeur d'une instance de la classe Case représentant une case du plateau de jeu Tetris
*/
void setLibereCase(Case * c);

/**
 * @brief Fonction qui permet d'attribuer une couleur à une case du plateau de jeu
 * @param c Un pointeur d'une instance de la classe Case représentant une case du plateau de jeu Tetris
 * @param color Un nombre entre 1 et 7 représentant une couleur
*/
void setColorCase(Case * c, unsigned char color);


/**
 * @brief Une fonction qui permet d'obtenir le nombre représentant la couleur d'une case
 * @param c Un pointeur d'une instance de la classe Case représentant une case du plateau de jeu Tetris
*/
char getColorCase(Case * c);

/**
 * @brief Une fonction qui renvoie un booléen indiquant si la case en paramètre est occupée ou non
 * @param c Un pointeur d'une instance de la classe Case représentant une case du plateau de jeu Tetris
*/
unsigned isOccupedCase(Case *c);

/**
 * @brief Une fonction qui permet de libéré l'espace occupé par un pointeur d'une case
 * @param c Un pointeur d'une instance de la classe Case représentant une case du plateau de jeu Tetris
*/
void deleteCase(Case * c);

/**
 * @brief Une fonction qui renvoie un pointeur d'une instance de la classe Case représentant une case du plateau de jeu Tetris qui est une copie du pointeur en paramètre
 * @param src Un pointeur d'une instance de la clase Case représentant une case du plateau de jeu Tetris
 * @return Un pointeur d'une instance de la clase Case représentant une case du plateau de jeu Tetris qui est une copie de celui en paramètre
*/
Case * copyCase(Case * src);