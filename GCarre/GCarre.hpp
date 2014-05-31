#include "../Hub/../Hub/Hub.hpp"
#ifndef GCarre_HPP
#define GCarre_HPP

//Représente la plus petite entité du jeu Tetris, soit un carré
class GCarre {
    RectangleShape square;
public :
    GCarre(Couleur col, Vector2f pos);
    ~GCarre() {};

    void handleEvent(Event& evt);
    void update(Time& delta);
    void draw(sf::RenderTarget& renderer);



};





#endif // GCarre_HPP
