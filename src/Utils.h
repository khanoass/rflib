#pragma once

#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace rf
{
	static const float PI = 3.141592654f;
	
	//
	// Zooms a given view on a given window by a given factor and re-center it on a given pixel relatively to the previous pixel
	//
	static void zoomViewAtPixel(sf::View& view, sf::RenderWindow& win, float factor, const sf::Vector2i& pixel, const sf::Vector2f& prevPos)
	{
		view.zoom(factor);
		win.setView(view);

		view.move(prevPos - win.mapPixelToCoords(pixel));
		win.setView(view);
	}
	
	//
	// Calculates the points in a 2D array that approximate a line from p1 to p2
	// The values in the "out" vector are true if they match the line path, false otherwise
	// This uses the Bresenham's line algorithm
	//
	static void getBresenhamLine(std::vector<std::vector<bool>>& grid, const sf::Vector2f& size, const sf::Vector2f& p1, const sf::Vector2f& p2)
	{
		const bool steep = (std::abs(p2.y - p1.y) > std::abs(p2.x - p1.x));
		
		if(steep)
		{
			std::swap(p1.x, p1.y);
			std::swap(p2.x, p2.y);
		}

		if(p1.x > p2.x)
		{
			std::swap(p1.x, p2.x);
			std::swap(p1.y, p2.y);
		}

		const float dx = p2.x - p1.x;
		const float dy = std::abs(p2.y - p1.y);

		float error = dx / 2.0f;
		const int ystep = (p1.y < p2.y) ? 1 : -1;
		int y = static_cast<int>(p1.y);

		const int maxX = static_cast<int>(p2.x);
		
		for(int y = 0; y < size.y; ++y)
		{
			out.push_back(std::vector<bool>());
			for(int x = 0; x < size.x; ++x)
				out[y].push_back(false);
		}

		for(int x = static_cast<int>(p1.x); x <= maxX; x++)
		{		
			(steep) ? out[x][y] = true : out[y][x] = true;

			error -= dy;
			if(error < 0)
			{
				y += ystep;
				error += dx;
			}
		}
		
		return out;
	}
}