#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include "ProjFactory.h"

// Базовый класс для пушек.
class Gun
{
private:
	// Ненормализованный вектор направления.
	sf::Vector2f direction;
protected:
	int hostility;
	std::string projName;
	sf::Time reloadTime;
	sf::Clock timer;
public:
	Gun(const sf::Vector2f direction, const std::string projName, const sf::Time reloadTime, const int hostility);
	sf::Vector2f getDirection() const;
	void setDirection(const sf::Vector2f direction);
	virtual std::list<Projectile*> shoot(const sf::Vector2f position) = 0;
};

class Shotgun : public Gun
{

};

class Machinegun : public Gun
{

};

// Махать мечом - получится ли?
class Swinger : public Gun
{

};

class Zapper : public Gun
{

};