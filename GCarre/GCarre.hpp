#include "../Piece/Piece.hpp"
#include <SFML/Graphics.hpp>

#ifndef GCarre_HPP
#define GCarre_HPP
using namespace sf;

//Représente la plus petite entité du jeu Tetris, soit un carré
class GCarre {
    RectangleShape square;
public :
    GCarre();
    ~GCarre() {};

    void init(Couleur col, Vector2f pos);
    void handleEvent(Event& evt);
    void update(Time& delta);
    void draw(sf::RenderTarget& renderer);



};





#endif // GCarre_HPP
