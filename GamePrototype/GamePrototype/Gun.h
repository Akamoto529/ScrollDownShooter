#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include "ProjFactory.h"
#include "Timer.h"

// Базовый класс для пушек.
class Gun
{
private:
	// Ненормализованный вектор направления.
	sf::Vector2f direction;
protected:
	bool frozen;
	int hostility;
	sf::Time reloadTime;
	Timer timer;
public:
	Gun(const sf::Vector2f direction, const sf::Time reloadTime);
	void freeze();
	sf::Vector2f getDirection() const;
	void setDirection(const sf::Vector2f direction);
	virtual std::list<Projectile*> shoot(const sf::Vector2f position) = 0;
	void unfreeze();
};

class Shotgun : public Gun
{

};

class Machinegun : public Gun
{

};