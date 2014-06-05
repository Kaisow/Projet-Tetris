#include "GCarre.hpp"

GCarre::GCarre()
{
}

void GCarre::init(Couleur col, Vector2f pos)
{
     square.setSize(Vector2f(25.0,25.0));
    square.setPosition(pos);
    switch(col) {
        case BLACK :
            square.setFillColor(Color(100,100,100));
            square.setOutlineColor(Color(50,50,50));
            square.setOutlineThickness(1);
            break;
        case CYAN :
            square.setFillColor(Color::Cyan);
            square.setOutlineColor(Color::Black);
            square.setOutlineThickness(1);
            break;
        case YELLOW :
            square.setFillColor(Color::Yellow);
            square.setOutlineColor(Color::Black);
            break;
        case GREEN :
            square.setFillColor(Color::Green);
            square.setOutlineColor(Color::Black);
            break;
        case RED :
            square.setFillColor(Color::Red);
            square.setOutlineColor(Color::Black);
            break;
        case BLUE :
            square.setFillColor(Color::Blue);
            square.setOutlineColor(Color::Black);
            break;
        case ORANGE :
            square.setFillColor(Color::Black);
            square.setOutlineColor(Color::Black);
            break;
        case GHOST :
            square.setFillColor(Color::Black);
            square.setOutlineColor(Color::Black);
            break;
    };
}

void GCarre::handleEvent(Event& evt)
{
}

void GCarre::update(Time& delta)
{
}

void GCarre::draw(sf::RenderTarget& renderer)
{
    renderer.draw(square);
}
