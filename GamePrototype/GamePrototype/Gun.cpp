#include "Gun.h"
#include <iostream>


// Gun.


Gun::Gun(const sf::Vector2f direction, const int projID, const sf::Time reloadTime, const int hostility)
{
	this->direction = direction;
	this->reloadTime = reloadTime;
	this->projID = projID;
	this->hostility = hostility;
	timer.restart();
}

sf::Vector2f Gun::getDirection() const
{
	return this->direction;
}

void Gun::setDirection(const sf::Vector2f direction)
{
	this->direction = direction;
}


// Rifle.


Rifle::Rifle(const sf::Vector2f direction, int projID, const int hostility)
	:Gun(direction, projID, sf::milliseconds(500), hostility)
{}

std::list<Projectile*> Rifle::shoot(const sf::Vector2f position)
{
	if (this->timer.getElapsedTime() >= this->reloadTime)
	{
		this->timer.restart();
		return{
			Projectile::createProjectile(this->projID, position, this->getDirection(), this->hostility)
		};
	}
	return {};
}