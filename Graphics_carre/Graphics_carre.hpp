#include "../Hub/../Hub/Hub.hpp"
#ifndef GRAPHICS_CARRE_HPP
#define GRAPHICS_CARRE_HPP

//Repr�sente la plus petite entit� du jeu Tetris, soit un carr�
class Graphics_carre {
    RectangleShape square;
public :
    Graphics_carre(Couleur col, Vector2i pos);
    ~Graphics_carre() {};

    void handleEvent(Event& evt);
    void update(Time& delta);
    void draw();



};





#endif // GRAPHICS_CARRE_HPP
