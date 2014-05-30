//-----------------------------------------------------------------------------
//  TD IHM
//  application.cpp
//-----------------------------------------------------------------------------

#include "Game.hpp"

//-----------------------------------------------------------------------------
//  Display
//-----------------------------------------------------------------------------

Display::Display(sf::RenderWindow& window) :
_displayView(window.getDefaultView()),
_window(window)
{
}

void Display::draw()
{
}

sf::Vector2f Display::getCenter()
{
	return _displayView.getCenter();
}

void Display::handleEvent(const sf::Event& evt)
{
}

void Display::update(sf::Time& tau)
{
}

//-----------------------------------------------------------------------------
//  Application
//-----------------------------------------------------------------------------

Game::Game() :
_scene(_window),
_window(sf::VideoMode(500, 500), "Evénements I")
{
}

void Game::run()
{
	sf::Clock clock;
	while (_window.isOpen())
	{
		sf::Time tau = clock.restart();
		processEvents();
		update(tau);
		render();
	}
}


void Game::processEvents()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
		_scene.handleEvent(event);

		if (event.type == sf::Event::Closed)
			_window.close();
	}

}

void Game::update(sf::Time& tau)
{
	_scene.update(tau);
}

void Game::render()
{
	_window.clear();
	_scene.draw();
	_window.display();
}

int main()
{
	Game _game;
	_game.run();
	return 0;
}
