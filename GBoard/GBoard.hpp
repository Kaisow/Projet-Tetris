#include "../GCarre/GCarre.hpp"
#include "../Board/Board.hpp"
#include <vector>

#ifndef GBoard_HPP
#define GBoard_HPP

using namespace sf;

class GBoard {
    GCarre          _carres[20][10];

    //Position définies au lancement du jeu, et permanente
    float positionX, positionY;


public :
    //Initialisation
    GBoard(Board& board, Vector2f center); //Initialise 20 cases vides
    ~GBoard(){}; //Destructeur

    //Gestionnaire des évènements
    void handleEvent(const Event& evt);

    //Mise à jour
    void update(Time& delta);

    //Affichage
    void draw(sf::RenderWindow& window);

    //Position précise
    sf::Vector2f setPrecisePosition(int i, int j, float positionX, float positionY);

};
#endif // GBoard_HPP
