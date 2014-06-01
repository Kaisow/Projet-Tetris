#include "GBoard.hpp"

GBoard::GBoard(Board& board, Vector2f center)
{
    float position_x = center.x -125, position_y = center.y - 250;
    for(int i=0; i<20; i++) {
        for(int j=0; j<10; j++) {
            _carres[i][j].init(BLACK, Vector2f(position_x, position_y));
            position_x += 26;
        }
        position_x = center.x - 125;
        position_y += 26;
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
