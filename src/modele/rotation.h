#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Structure représentant une des rotations possibles d'une pièce de Tetris
*/
typedef struct _rotation
{
    unsigned char hauteur;
    unsigned char largeur;
    unsigned char xCentre;
    unsigned char yCentre;
    bool * tab;
}Rotation;

/**
 * @brief Structure représentant toutes les rotations d'une pièce de Tetris
*/
typedef struct _rotations
{
    unsigned char nbRotations;
    Rotation ** tabRota;
}Rotations;

/**
 * @brief Fonction permettant de créer un pointeur d'une instance de la classe Rotations contenant les données nécessaire pour pouvoir réaliser les rotations d'une pièce
 * @param typePiece Nombre représentant le type de pièce
 * @return Un pointeur d'une instance de la classe Rotations contenant les données nécessaire pour representer les rotations d'une pièce
*/
Rotations * initRotations(int typePiece) ;


/**
 * @brief Fonction qui permet de libéré l'espace alloué à un pointeur représentant les rotations d'une pièce
 * @param r Un pointeur d'une instance de la classe Rotations contenant les données nécessaire pour representer les rotations d'une pièce
*/
void deleteRotations(Rotations * r);