#pragma once
#include "plateau.h"


/**
 * @brief Structure principale du modèle du jeu Tetris contenant le plateau, la piece à poser ainsi que les informations du jeu
*/
typedef struct _partie
{
    long unsigned score;
    long unsigned scoreProchainNiveau;
    unsigned char niveau;
    Plateau * plateauDeJeu;
    Piece * piece;
} Partie;


/**
 * @brief Fonction permettant de créer un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
 * @param ligne Nombre de ligne du plateau de jeu de Tetris
 * @param colonne Nombre de colonne du plateau de jeu Tetris
 * @return Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
*/
Partie * initPartie(unsigned char ligne, unsigned char colonne);


/**
 * @brief Une fonction qui permet de libéré l'espace occupé par un pointeur d'une partie
 * @param p Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
*/
void deletePartie(Partie * p);

/**
 * @brief Fonction qui renvoie un booléen indiquant si la partie de Tetris est finie ou non
 * @param p Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
 * @return Booléen indiquant si la partie est finie ou non
*/
unsigned finDePartie(Partie *p);


/**
 * Fonction qui permet d'augmenter le score de la partie
 * @param p pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
 * @param nb Nombre représentant la quantité de score à augmenter
*/
void addScorePartie(Partie * p, unsigned long nb);


/**
 * @brief Fonction qui s'occupe des niveaux de la partie de tetris
 * @param p Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
*/
void gestionDeNiveauPartie(Partie * p);

/**
 * @brief Fonction qui vérifie si une ligne est supprimable, renvoie true et la supprime sinon renvoie faux
 * @param p Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
 * @param i Indice de la ligne à supprimer
 * @return Un booléen indiquant que la ligne a été supprimée ou non
*/
bool deleteLignePartie(Partie * p, unsigned i);

/**
 * @brief Fonction qui s'occupe du score et de la suppression des lignes
 * @param p Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
*/
void gestionLignesPartie(Partie *p);


/**
 * @brief Une fonction qui permet de faire tomber la ligne i - 1 sur la ligne i
 * @param p Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
 * @param i Indice de la ligne vide
*/
void ligneTombePartie(Partie * p, unsigned i);


/**
 * @brief Une fonction qui permet d'ajouter une nouvelle pièce à la partie
 * @param p Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
*/
void addPiecePartie(Partie *p) ;


/**
 * @brief Une fonction qui permet de passer à l'étape suivante (faire tomber la pièce où d'en ajouter une nouvelle)
 * @param p Un pointeur d'une instance de la classe Partie contenant les données nécessaire pour jouer à Tetris
 * @return Un booléen qui indique si la partie est fini ou non
*/
bool prochaineEtape(Partie * p);