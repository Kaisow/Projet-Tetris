#include "../Hub/Hub.hpp"

Board::Board()
{
       /* On initialise toutes les cases de l'aire de jeu à FREE (0) */
    for(int i = 0; i < BOARD_WIDTH; ++i)
        for(int j = 0; j < BOARD_HEIGHT; ++j)
            area[i][j] = FREE;
}

//Configuration de la piède jouable
void Board::setCurrentPiece(Piece p)
{
    currentPiece = p;
}

//Pièce actuellement jouée
Piece Board::getCurrentPiece()
{
    return currentPiece;
}
