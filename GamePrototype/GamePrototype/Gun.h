#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Projectile.h"

// Базовый класс для пушек.
class Gun
{
	// Ненормализованный вектор направления.
	sf::Vector2f direction;
protected:
	int projID;
	sf::Time reloadTime;
	sf::Clock timer;
	Entity* owner;
public:
	Gun(const sf::Vector2f direction, const int projID, const sf::Time reloadTime, Entity* owner);
	sf::Vector2f getDirection() const;
	void setDirection(const sf::Vector2f direction);
	virtual std::list<Projectile*> Shoot(const sf::Vector2f position) = 0;
};

// Reload = 500 msec.
// Полуавтоматическая винтовка.
class Rifle : public Gun
{
public:
	Rifle(const sf::Vector2f direction, int projID, Entity* owner);
	std::list<Projectile*> Shoot(const sf::Vector2f position);
};

class Shotgun : public Gun
{

};

class Machinegun : public Rifle
{

};

// Махать мечом - получится ли?
class Swinger : public Gun
{

};

class Zapper : public Gun
{

};