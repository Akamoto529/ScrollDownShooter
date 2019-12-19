#pragma once
#include "SFML/Graphics.hpp"
#include "config.h"
#include <list>

class Hitbox : public sf::Transformable, public sf::Drawable
{
	float area;
	sf::FloatRect boundingBox;
	// ѕоложени€ точек относительно левого верхнего угла текстуры.
	std::list<sf::Vector2f> vertices;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Hitbox();
	Hitbox(std::list<sf::Vector2f> vertices);
	float getArea() const;
	sf::FloatRect getGlobalBounds() const;
	//  оординаты точек на игровом поле.
	std::list<sf::Vector2f> getVerticesAbs() const;
	void rotate(const float angle);
	void setRotation(const float angle);
	static float TriangleArea(const sf::Vector2f a, const sf::Vector2f b, const sf::Vector2f c);
};