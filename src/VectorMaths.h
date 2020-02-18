#include <cmath>
#include <SFML/System/Vector2.hpp>

namespace rf
{
	static float getMagnitudeSquared(const sf::Vector2f& v)
	{
		return v.x*v.x + v.y*v.y;
	}

	static float getMagnitude(const sf::Vector2f& v)
	{
		return std::sqrt(getMagnitudeSquared(v));
	}

	static sf::Vector2f normalize(const sf::Vector2f& v)
	{
		return sf::Vector2f{ v.x / getMagnitude(v), v.y / getMagnitude(v) };
	}

	static float dotProduct(const sf::Vector2f& a, const sf::Vector2f& b)
	{
		return a.x * b.x + a.x * b.y;
	}

	static sf::Vector2f rotate(const sf::Vector2f& v, float rad)
	{
		return sf::Vector2f{ std::cos(rad) * v.x - std::sin(rad) * v.y, std::sin(rad) * v.x + std::cos(rad) * v.y };
	}

	static sf::Vector2f setMagnitude(const sf::Vector2f& v, float length)
	{
		return normalize(v) * length;
	}

	static float getAngleBeetween(const sf::Vector2f& a, sf::Vector2f& b)
	{
		return dotProduct(a, b) / (getMagnitude(a) * getMagnitude(b));
	}
}