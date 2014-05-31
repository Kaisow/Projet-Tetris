#include "Graphics_carre.hpp"

Graphics_carre::Graphics_carre(Couleur col, Vector2f pos)
{
    square.setSize(Vector2f(25.0,25.0));
    square.setPosition(pos);

    switch(col) {
        case BLACK :
            square.setFillColor(Color::Black);
            square.setOutlineColor(Color::White);
            square.setOutlineThickness(1);
            break;
        case CYAN :
            square.setFillColor(Color::Cyan);
            square.setOutlineColor(Color::Black);
            square.setOutlineThickness(1);
            break;
        case YELLOW :
            square.setFillColor(Color::Yellow);
            break;
        case GREEN :
            square.setFillColor(Color::Green);
            break;
        case RED :
            square.setFillColor(Color::Red);
            break;
        case BLUE :
            square.setFillColor(Color::Blue);
            break;
        case ORANGE :
            square.setFillColor(Color::Black);
            break;
        case GHOST :
            square.setFillColor(Color::Black);
            break;
    };
}

void Graphics_carre::draw(sf::RenderTarget& renderer)
{
    renderer.draw(square);
}
