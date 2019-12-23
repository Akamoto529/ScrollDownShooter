#include "Gun.h"
#include <iostream>


// Gun.


Gun::Gun(const sf::Vector2f direction, const sf::Time reloadTime, const int hostility)
{
	this->direction = direction;
	this->frozen = false;
	this->hostility = hostility;
	this->reloadTime = reloadTime;
	timer.reset();
}

void Gun::freeze()
{
	this->frozen = true;
	this->timer.pause();
}

sf::Vector2f Gun::getDirection() const
{
	return this->direction;
}

void Gun::setDirection(const sf::Vector2f direction)
{
	this->direction = direction;
}

void Gun::unfreeze()
{
	this->frozen = false;
	this->timer.start();
}