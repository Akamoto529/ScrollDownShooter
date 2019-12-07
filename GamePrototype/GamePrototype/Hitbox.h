#pragma once
#include "SFML/Graphics.hpp"
#include <list>

class Hitbox : public sf::Transformable
{
	// ����� ���������� ��� list?
	// ��������� ����� ������������ ����� ������� � ��������.
	std::list<sf::Vector2f> vertices;
	float area;
public:
	Hitbox();
	Hitbox(std::list<sf::Vector2f> vertices);
	float getArea() const;
	// ���������� ����� �� ������� ����.
	std::list<sf::Vector2f> getVerticesAbs() const;
	static float TriangleArea(const sf::Vector2f a, const sf::Vector2f b, const sf::Vector2f c);
};

