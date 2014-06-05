/* board.h */
#include "../Shapes/Shapes.hpp"
#include "../Piece/Piece.hpp"
#ifndef BOARD_H
#define BOARD_H

//FREE la grille est vide (elle contient 0)
//OCCUPED la grille contient une valeur diff�rente de 0
enum { FREE,  OCCUPED };

struct Case {
    int type;
    int state;
    int kind;
};

const int BOARD_HEIGHT = 20; // La hauteur de l'aire de jeu
const int BOARD_WIDTH = 10; // Sa largeur

const int ORIGIN_X = 0; // L'ordonn�e du point de pivot
const int ORIGIN_Y = 5; // Son absisse

class Board
{
private:
    Piece currentPiece; // La pi�ce courante se trouvant sur l'aire de jeu

public:
    Case area[BOARD_WIDTH][BOARD_HEIGHT]; // Le tableau repr�sentant l'aire de jeu

    Board(); //Constructeur

    int getState(int i, int j);

    void setCurrentPiece(Piece p); //Configuration pi�ce acctuellement d�placeable
    Piece getCurrentPiece(); //Obtention de la pi�ce actuellemetn d�pla�able
    //Algorithme du floodFill (Test de remplissage des cases)
    void flood(int i, int j, int px, int py, int k, int o, int value, bool visited[][SIZE]);
    void flood(int i, int j, int px, int py, int k, int o, bool &flag, bool visited[][SIZE]); //Surd�finition (anti-colisions)

    void floodFill(int i, int j, int px, int py, int k, int o, int value);


    //Graphique ------------------------------------------------
    void drawPiece(Piece p); //Dessiner une pi�ce
    void clearPiece(Piece p); //Effacer une pi�ce
    void newPiece(Piece p); //Spawn d'une pi�ce
    void clear(); //R�initialisation de toute l'aire de jeu

    bool isCurrentPieceMovable(int x, int y); //V�rifie si la pi�ce peut �tre d�plac�e � la position x, y
    bool isCurrentPieceRotable(int o); //V�rifie si la pi�ce peut peut �tre retourn�e

    void moveCurrentPieceDown(); //Di�placement pi�ce vers le bas
    void moveCurrentPieceLeft(); //D�placement pi�ce vers la gauche
    void moveCurrentPieceRight(); //d�placement pi�ce vers la droite

    void rotateCurrentPieceLeft(); //Tourner la pi�ce � gauche
    void rotateCurrentPieceRight(); //Tourner la pi�ce � droite

    void deleteLine(int y); // Supprime la ligne se trouvant � la position y
    int deletePossibleLines(); // V�rifie s'il existe des lignes pleines et les supprime
    void dropCurrentPiece(); // Hard Drop (Toutes les pi�ces unt fois qu'une ligne est supprim�e)
    bool isCurrentPieceFallen(); // La pi�ce courante est-elle tomb�e ?
    bool isGameOver(); // La partie est-elle finie ?
};

#endif
