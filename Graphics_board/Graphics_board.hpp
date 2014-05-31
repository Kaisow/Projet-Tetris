#include "../Hub/Hub.hpp"

#ifndef GRAPHICS_BOARD_HPP
#define GRAPHICS_BOARD_HPP
using namespace sf;

class Graphics_carre;
class Graphics_board {

public :
    //Initialisation
    Graphics_board(Board& board, Vector2f center); //Initialise 20 cases vides
    ~Graphics_board(){}; //Destructeur

    //Gestionnaire des évènements
    void handleEvent(const Event& evt);

    //Mise à jour
    void update(Time& delta);

    //Affichage
    void draw();

};
#endif // GRAPHICS_BOARD_HPP
