#pragma once
#include "SFML/Graphics.hpp"

// Суперкласс для физических игровых объектов
class Entity : public sf::Drawable, public sf::Transformable
{
public:
	// Оценка для проверки выхода за границу экрана.
	virtual float getDiameter() = 0;
};
