#include "../Hub/Hub.hpp"

#ifndef GRAPHICS_BOARD_HPP
#define GRAPHICS_BOARD_HPP
using namespace sf;

class Graphics_board {
    Board       _board;

public :
    //Initialisation
    Graphics_board(); //Initialise 20 cases vides
    ~Graphics_board(){}; //Destructeur

    //Gestionnaire des évènements
    void handleEvent(const Event& evt);

    //Mise à jour
    void update(Time& delta);

    //Affichage
    void draw();

};
#endif // GRAPHICS_BOARD_HPP
