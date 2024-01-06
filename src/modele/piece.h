#pragma once
typedef struct _plateau Plateau;

#include "plateau.h"
#include "rotation.h"

/**
 * @brief Une structure représentant une pièce de jeu de Tetris
*/
typedef struct _piece
{
    unsigned char idPiece;
    unsigned char idRotation;
    unsigned canRotate : 1;
    unsigned char hauteur;
    unsigned char largeur;
    unsigned char x;
    unsigned char y;
    unsigned char color;
    unsigned char xCoordsCentre;
    unsigned char yCoordsCentre;
    Case ** cases;  
} Piece;



/**
 * @brief Fonction permettant de créer un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
 * @param p Un pointeur d'une instance de la classe Plateau contenant les données nécessaire pour représenter un plateau de jeu de Tetris
 * @return Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
*/
Piece * initPiece(Plateau * p) ;


/**
 * @brief Fonction qui permet de libéré l'espace alloué à un pointeur représentant une Pièce de jeu Tetris
 * @param p Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
*/
void deletePiece(Piece * p);

/**
 * @brief Fonction qui fait tomber de une ligne la pièce en paramètre
 * @param p Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
*/
void tombePiece(Piece *p);

/**
 * @brief Fonction qui déplace d'une case à gauche la pièce en paramètre
 * @param p Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
*/
void deplacementGauchePiece(Piece * p);


/**
 * @brief Fonction qui déplace d'une case à droite la pièce en paramètre
 * @param p Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
*/
void deplacementDroitePiece(Piece * p);

/**
 * @brief Fonction qui fait faire une rotation vers la droite à la pièce en paramètre
 * @param p Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
*/
void rotationPiece(Piece * p);

/**
 * @brief Fonction qui permet de faire une copie de la pièce en paramètre
 * @param p Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
 * @return Copie du pointeur en paramètre
*/
Piece * copyPiece(Piece * p);


/**
 * @brief Fonction qui permet d'initialiser une nouvelle pièce différente de la précédebte*
 * @param p Un pointeur d'une instance de la classe Plateau contenant les données nécessaire pour représenter un plateau de jeu de Tetris
 * @param idp Nombre représentant le type de la dernière pièce
 * @return Un pointeur d'une instance de la classe Piece contenant les données nécessaire pour representer une piece pour jouer à Tetris
*/
Piece * initNewPiece(Plateau * p, unsigned char idp) ;