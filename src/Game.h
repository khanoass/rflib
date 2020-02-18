#pragma once

#include <iostream>

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>

namespace rf
{
	//
	// Base class for any game-like application
	// Construct with windowSize, windowStyle, windowTitle, updateTime and font parameters
	// Provides basic functions for initialisation, updation, rendering and event management
	//
	class Game
	{
	public:
		Game() = delete;
		Game(const sf::Vector2u& windowSize, const sf::Uint32& windowStyle, const std::string& windowTitle, const sf::Time& updateTime, const sf::Font& font);

		void run();

	protected:
		sf::Vector2u _windowSize;
		sf::Uint32 _windowStyle;
		std::string _windowTitle;
		sf::Time _updateTime;
		sf::Font _font;

		sf::RenderWindow _win;
		sf::Clock _updateClock;
		sf::Event _event;

		virtual void init() = 0;
		virtual void update() = 0;
		virtual void updateEvents() = 0;
		virtual void render() = 0;
	};
}