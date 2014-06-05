/* board.h */
#include "../Shapes/Shapes.hpp"
#include "../Piece/Piece.hpp"
#ifndef BOARD_H
#define BOARD_H

//FREE la grille est vide (elle contient 0)
//OCCUPED la grille contient une valeur différente de 0
enum { FREE,  OCCUPED };

struct Case {
    int type;
    int state;
    int kind;
};

const int BOARD_HEIGHT = 20; // La hauteur de l'aire de jeu
const int BOARD_WIDTH = 10; // Sa largeur

const int ORIGIN_X = 0; // L'ordonnée du point de pivot
const int ORIGIN_Y = 5; // Son absisse

class Board
{
private:
    Piece currentPiece; // La pièce courante se trouvant sur l'aire de jeu

public:
    Case area[BOARD_WIDTH][BOARD_HEIGHT]; // Le tableau représentant l'aire de jeu

    Board(); //Constructeur

    int getState(int i, int j);

    void setCurrentPiece(Piece p); //Configuration pièce acctuellement déplaceable
    Piece getCurrentPiece(); //Obtention de la pièce actuellemetn déplaçable
    //Algorithme du floodFill (Test de remplissage des cases)
    void flood(int i, int j, int px, int py, int k, int o, int value, bool visited[][SIZE]);
    void flood(int i, int j, int px, int py, int k, int o, bool &flag, bool visited[][SIZE]); //Surdéfinition (anti-colisions)

    void floodFill(int i, int j, int px, int py, int k, int o, int value);


    //Graphique ------------------------------------------------
    void drawPiece(Piece p); //Dessiner une pièce
    void clearPiece(Piece p); //Effacer une pièce
    void newPiece(Piece p); //Spawn d'une pièce
    void clear(); //Réinitialisation de toute l'aire de jeu

    bool isCurrentPieceMovable(int x, int y); //Vérifie si la pièce peut être déplacée à la position x, y
    bool isCurrentPieceRotable(int o); //Vérifie si la pièce peut peut être retournée

    void moveCurrentPieceDown(); //Diéplacement pièce vers le bas
    void moveCurrentPieceLeft(); //Déplacement pièce vers la gauche
    void moveCurrentPieceRight(); //déplacement pièce vers la droite

    void rotateCurrentPieceLeft(); //Tourner la pièce à gauche
    void rotateCurrentPieceRight(); //Tourner la pièce à droite

    void deleteLine(int y); // Supprime la ligne se trouvant à la position y
    int deletePossibleLines(); // Vérifie s'il existe des lignes pleines et les supprime
    void dropCurrentPiece(); // Hard Drop (Toutes les pièces unt fois qu'une ligne est supprimée)
    bool isCurrentPieceFallen(); // La pièce courante est-elle tombée ?
    bool isGameOver(); // La partie est-elle finie ?
};

#endif
