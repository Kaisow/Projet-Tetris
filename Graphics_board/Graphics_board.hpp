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

    //Gestionnaire des �v�nements
    void handleEvent(const Event& evt);

    //Mise � jour
    void update(Time& delta);

    //Affichage
    void draw();

};
#endif // GRAPHICS_BOARD_HPP
