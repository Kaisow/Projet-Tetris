#include "../Hub/Hub.hpp"

#ifndef GBoard_HPP
#define GBoard_HPP
using namespace sf;

class GBoard {

public :
    //Initialisation
    GBoard(Board& board, Vector2f center); //Initialise 20 cases vides
    ~GBoard(){}; //Destructeur

    //Gestionnaire des �v�nements
    void handleEvent(const Event& evt);

    //Mise � jour
    void update(Time& delta);

    //Affichage
    void draw();

};
#endif // GBoard_HPP
