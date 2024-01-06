#pragma once
#include "case.h"
typedef struct _piece Piece;
#include "piece.h"
#include <stdbool.h>

/**
 * @brief Structure représentant le plateau de jeu de Tetris
*/
typedef struct _plateau
{
    unsigned char nbLigne;
    unsigned char nbColonne;
    Case ** tab;
} Plateau;


/**
 * @brief Fonction permettant de créer un pointeur d'une instance de la classe Plateau représentant ke plateau de jeu Tetris
 * @param nbLigne Nombre de ligne du plateau
 * @param nbColonne Nombre de colonne du plateau
 * @return Un pointeur d'une instance de la classe Plateau représentant ke plateau de jeu Tetris
*/
Plateau * initPlateau(unsigned char nbLigne, unsigned char nbColonne);

/**
 * @brief Une fonction qui permet de libéré l'espace occupé par un pointeur du tableau de jeu de Tetris
 * @param p Un pointeur d'une instance de la classe Plateau représentant ke plateau de jeu Tetris
*/
void deletePlateau(Plateau * p);

/**
 * @brief Fonction qui permet de faire une  copie du plateau de jeu
 * @param src Un pointeur d'une instance de la classe Plateau représentant le plateau de jeu Tetris
 * @return Un pointeur d'une instance de la classe Plateau représentant la copie du plateau en paramètre
*/
Plateau * copyPlateau(Plateau * src) ;

/**
 * @brief Fonction qui permet de faire une  copie du plateau de jeu en ajoutant la pièce en paramètre
 * @param plat Un pointeur d'une instance de la classe Plateau représentant le plateau de jeu Tetris
 * @param piece Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
*/
Plateau * plateauWithPiece(Plateau * plat, Piece * piece);

/**
 * @brief Fonction permettant d'obtenir un pointeur de type Case à l'indice i et j du plateau
 * @param p Un pointeur d'une instance de la classe Plateau représentant ke plateau de jeu Tetris
 * @param i Nombre représentant l'indice de la ligne de la case désirée
 * @param j Nombre représentant l'indice de la ligne de la case désirée
 * @return Pointeur de la case aux indices donnés en paramètre
*/
Case * getCase(Plateau *p, int i, int j);


/**
 * @brief Fonction renvoyant indiquant que la pièce peut faire une rotation dans le plateau ou non
 * @param pl Un pointeur d'une instance de la classe Plateau représentant ke plateau de jeu Tetris
 * @param pi Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
 * @return Booléen indiquant que la pièce peut faire une rotation vers la droite ou non
*/
bool peutRotatePlateau(Plateau *pl, Piece * pi);


/**
 * @brief Fonction renvoyant indiquant que la pièce peut bouger à gauche ou non
 * @param pl Un pointeur d'une instance de la classe Plateau représentant ke plateau de jeu Tetris
 * @param pi Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
 * @return Booléen indiquant que la pièce peut bouger à gauche ou non
*/
bool peutBougerGauchePlateau(Plateau *pl, Piece * pi);


/**
 * @brief Fonction renvoyant indiquant que la pièce peut bouger à droite ou non
 * @param pl Un pointeur d'une instance de la classe Plateau représentant ke plateau de jeu Tetris
 * @param pi Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
 * @return Booléen indiquant que la pièce peut bouger à droite ou non
*/
bool peutBougerDroitePlateau(Plateau *pl, Piece * pi);

/**
 * @brief Fonction renvoyant indiquant que la pièce peut tomber ou non
 * @param pl Un pointeur d'une instance de la classe Plateau représentant ke plateau de jeu Tetris
 * @param pi Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
 * @return Booléen indiquant que la pièce peut tomber ou non
*/
bool peutTomberPlateau(Plateau *pl, Piece * pi);


/**
 * @brief Fonction qui permet de déposer une pièce dans le plateau 
 * @param pl Un pointeur d'une instance de la classe Plateau représentant ke plateau de jeu Tetris
 * @param pi Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
*/
void deposePiecePlateau(Plateau *pl, Piece * pi);