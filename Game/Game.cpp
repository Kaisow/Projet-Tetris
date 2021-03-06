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
_window(window), _gBoard(_board, getCenter())
{
}

void Display::draw()
{
    _gBoard.draw(_window);
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
_window(sf::VideoMode(800, 600), "Evénements I", Style::Close | Style::Titlebar),_display(_window)
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
		_display.handleEvent(event);

		if (event.type == sf::Event::Closed)
			_window.close();
	}

}

void Game::update(sf::Time& tau)
{
	_display.update(tau);
}

void Game::render()
{
	_window.clear();
	_display.draw();
	_window.display();
}

int main()
{
	Game _game;
	_game.run();
	return 0;
}
