//-----------------------------------------------------------------------------
//  TD IHM
//  application.hpp
//-----------------------------------------------------------------------------

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>
#include "../Hub//Hub.hpp"

using namespace std;

//-----------------------------------------------------------------------------
//  Display
//-----------------------------------------------------------------------------

class Display
{
private:
	// Graphique
	sf::View				_displayView;
	sf::RenderWindow&		_window;

public:
	// Constructeur & destructeur
	Display(sf::RenderWindow& window);
	~Display(){};

	// Requêtes graphiques
	sf::Vector2f getCenter();

	// Gestion des événements
	void handleEvent(const sf::Event& evt);

	// Mise à jour
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
	Display					_scene;

public:
	Game();
	void run();

protected:
	// Boucle événementielle
	void processEvents();
	void update(sf::Time& delta);
	void render();
};
#endif //GAME_H
