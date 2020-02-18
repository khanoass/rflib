#include "Game.h"

namespace rf
{
	Game::Game(const sf::Vector2u& windowSize, const sf::Uint32& windowStyle, const std::string& windowTitle, const sf::Time& updateTime, const sf::Font& font) :
		_windowSize(windowSize),
		_windowStyle(windowStyle),
		_windowTitle(windowTitle),
		_updateTime(updateTime),
		_font(font)
	{
	}

	void Game::run()
	{
		_win.create(sf::VideoMode(_windowSize.x, _windowSize.y), _windowTitle, _windowStyle);
		init();

		while (_win.isOpen())
		{
			while (_win.pollEvent(_event))
				updateEvents();

			if (_updateClock.getElapsedTime() > _updateTime)
			{
				_updateClock.restart();
				update();

				_win.clear();
				render();
				_win.display();
			}
		}
	}
}