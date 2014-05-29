#include "../Hub/Hub.hpp"

Board::Board()
{
       /* On initialise toutes les cases de l'aire de jeu � FREE (0) */
    for(int i = 0; i < BOARD_WIDTH; ++i)
        for(int j = 0; j < BOARD_HEIGHT; ++j)
            area[i][j] = FREE;
}

//Configuration de la pi�de jouable
void Board::setCurrentPiece(Piece p)
{
    currentPiece = p;
}

//Pi�ce actuellement jou�e
Piece Board::getCurrentPiece()
{
    return currentPiece;
}
