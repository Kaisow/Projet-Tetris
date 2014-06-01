#include "../GCarre/GCarre.hpp"
#include "../Board/Board.hpp"

#ifndef GBoard_HPP
#define GBoard_HPP

using namespace sf;

class GBoard {
    GCarre         carre[20][10];

public :
    //Initialisation
    GBoard(); //Initialise 20 cases vides
    ~GBoard(){}; //Destructeur

    void init(Board& board, Vector2f center);
    //Gestionnaire des évènements
    void handleEvent(const Event& evt);

    //Mise à jour
    void update(Time& delta);

    //Affichage
    void draw();

};
#endif // GBoard_HPP
