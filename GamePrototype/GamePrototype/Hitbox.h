#pragma once
#include "SFML/Graphics.hpp"
#include <list>
#include <vector>

class Hitbox : public sf::Transformable
{
	// ����� ���������� ��� list?
	// ��������� ����� ������������ ����� ������� � ��������.
	std::vector<sf::Vector2f> vertices;
	float area;
public:
	Hitbox();
	Hitbox(std::list<sf::Vector2f> vertices);
	// ���������� ����� �� ������� ����.
	std::list<sf::Vector2f> getVerticesAbs() const;
	static float TriangleArea(const sf::Vector2f a, const sf::Vector2f b, const sf::Vector2f c);
};

