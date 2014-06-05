#include "GBoard.hpp"

GBoard::GBoard(Board& board, Vector2f center)
{
    float positionX = center.x -360, positionY = center.y - 265;
    for(int i=0; i<20; i++) {
        for(int j=0; j<10; j++) {
            _carres[i][j].init(BLACK, setPrecisePosition(i, j, positionX, positionY));
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


sf::Vector2f GBoard::setPrecisePosition(int i, int j, float positionX, float positionY)
{
    return Vector2f(Vector2f(positionX + 26 * j, positionY + 26 * i));
}
