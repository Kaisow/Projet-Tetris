#include "GBoard.hpp"

GBoard::GBoard(Board& board, Vector2f center)
{
    float positionX = center.x -250, positionY = center.y - 250;
    for(int i=0; i<20; i++) {
        for(int j=0; j<10; j++) {
            _carres[i][j].init(BLACK, Vector2f(positionX + 26 * j, positionY + 26 * i));
        }
    }
}


void GBoard::draw(sf::RenderWindow& window)
{
    for(int i=0; i<20; i++) {
        for(int j=0; j<10; j++) {
            _carres[i][j].draw(window);
        }
    }
}

