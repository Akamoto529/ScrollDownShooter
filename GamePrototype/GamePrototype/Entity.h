#pragma once
#include "SFML/Graphics.hpp"

// ���������� ��� ���������� ������� ��������
class Entity : public sf::Drawable, public sf::Transformable
{
public:
	// ������ ��� �������� ������ �� ������� ������.
	virtual float getRadius() = 0;
};
