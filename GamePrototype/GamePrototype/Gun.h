#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

// Базовый класс для пушек.
class Gun
{
	// Ненормализованный вектор направления.
	sf::Vector2f direction;
protected:
	sf::Time reload;
	sf::Clock timer;
public:
	// Текстура снаряда для тестов.
	sf::Texture projTx;
	Gun(sf::Vector2f direction);
	sf::Vector2f getDirection();
	void setDirection(sf::Vector2f direction);
	// Добавление снарядов в сцену.
	virtual void Shoot(Scene* scene, sf::Vector2f position) = 0;
};

class Rifle : public Gun
{
public:
	Rifle(sf::Vector2f direction);
	void Shoot(Scene* scene, sf::Vector2f position);
};