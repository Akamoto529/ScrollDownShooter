#pragma once
#include "SFML/Graphics.hpp"
#include <list>

class Hitbox : public sf::Transformable
{
	// Можно переделать для list?
	// Положения точек относительно точки отсчета в хитбоксе.
	std::list<sf::Vector2f> vertices;
	float area;
public:
	Hitbox();
	Hitbox(std::list<sf::Vector2f> vertices);
	float getArea() const;
	// Координаты точек на игровом поле.
	std::list<sf::Vector2f> getVerticesAbs() const;
	static float TriangleArea(const sf::Vector2f a, const sf::Vector2f b, const sf::Vector2f c);
};

