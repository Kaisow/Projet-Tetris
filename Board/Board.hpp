/* board.h */
#include "../Hub/Hub.hpp"
#ifndef BOARD_H
#define BOARD_H

//FREE la grille est vide (elle contient 0)
//OCCUPED la grille contient une valeur diff�rente de 0
enum  { FREE,  OCCUPED };

const int BOARD_HEIGHT = 20; // La hauteur de l'aire de jeu
const int BOARD_WIDTH = 10; // Sa largeur

const int ORIGIN_X = 0; // L'ordonn�e du point de pivot
const int ORIGIN_Y = 5; // Son absisse

class Board
{
private:
    Piece currentPiece; // La pi�ce courante se trouvant sur l'aire de jeu

public:
    int area[BOARD_WIDTH][BOARD_HEIGHT]; // Le tableau repr�sentant l'aire de jeu

    Board(); //Constructeur

        void setCurrentPiece(Piece p); //Configuration pi�ce acctuellement d�placeable
        Piece getCurrentPiece(); //Obtention de la pi�ce actuellemetn d�pla�able
};

#endif
