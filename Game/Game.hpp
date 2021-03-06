//-----------------------------------------------------------------------------
//  TD IHM
//  application.hpp
//-----------------------------------------------------------------------------

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>
#include "../GBoard/GBoard.hpp"
#include "../GCarre/GCarre.hpp"

using namespace std;
using namespace sf;

//-----------------------------------------------------------------------------
//  Display
//-----------------------------------------------------------------------------
class Graphics_carre;
class Graphics_board;
class Display
{
private:
	// Graphique
	sf::View				_displayView;
	sf::RenderWindow&		_window;
	Board                   _board;
	GBoard                  _gBoard;

public:
	// Constructeur & destructeur
	Display(sf::RenderWindow& window);
	~Display(){};

	// Requ�tes graphiques
	sf::Vector2f getCenter();

	// Gestion des �v�nements
	void handleEvent(const sf::Event& evt);

	// Mise � jour
	void update(sf::Time& delta);

	// Rendu
	void draw();
};

//-----------------------------------------------------------------------------
//  Game
//-----------------------------------------------------------------------------

class Game
{
	// Graphique
	sf::RenderWindow		_window;

	// Logique
	Display					_display;

public:
	Game();
	void run();

protected:
	// Boucle �v�nementielle
	void processEvents();
	void update(sf::Time& delta);
	void render();
};
#endif //GAME_H
