/* board.h */
#include "../Hub/Hub.hpp"
#ifndef BOARD_H
#define BOARD_H

//FREE la grille est vide (elle contient 0)
//OCCUPED la grille contient une valeur différente de 0
enum  { FREE,  OCCUPED };

const int BOARD_HEIGHT = 20; // La hauteur de l'aire de jeu
const int BOARD_WIDTH = 10; // Sa largeur

const int ORIGIN_X = 0; // L'ordonnée du point de pivot
const int ORIGIN_Y = 5; // Son absisse

class Board
{
private:
    Piece currentPiece; // La pièce courante se trouvant sur l'aire de jeu

public:
    int area[BOARD_WIDTH][BOARD_HEIGHT]; // Le tableau représentant l'aire de jeu

    Board(); //Constructeur

        void setCurrentPiece(Piece p); //Configuration pièce acctuellement déplaceable
        Piece getCurrentPiece(); //Obtention de la pièce actuellemetn déplaçable
};

#endif
