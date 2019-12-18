#pragma once
#include "SFML/Graphics.hpp"
#include <list>

class Hitbox : public sf::Transformable, public sf::Drawable
{
	// ����� ���������� ��� list?
	// ��������� ����� ������������ ����� ������� � ��������.
	std::list<sf::Vector2f> vertices;
	float area;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Hitbox();
	Hitbox(std::list<sf::Vector2f> vertices);
	float getArea() const;
	// ���������� ����� �� ������� ����.
	std::list<sf::Vector2f> getVerticesAbs() const;
	static float TriangleArea(const sf::Vector2f a, const sf::Vector2f b, const sf::Vector2f c);
};