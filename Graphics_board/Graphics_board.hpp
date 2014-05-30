#include "../Hub/Hub.hpp"
using namespace sf;
class Graphics_board {
    RectangleShape _square;

public :
    //Initialisation
    Graphics_board();
    ~Graphics_board(){};

    void handleEvent(const Event& evt);

    void update(Time& delta);

    void draw();

};
