#include "Gun.h"
#include <iostream>


// Gun.


Gun::Gun(const sf::Vector2f direction, const int projID, const sf::Time reloadTime, Entity* owner)
{
	this->direction = direction;
	this->reloadTime = reloadTime;
	this->projID = projID;
	this->owner = owner;
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


Rifle::Rifle(const sf::Vector2f direction, int projID, Entity* owner)
	:Gun(direction, projID, sf::milliseconds(500), owner)
{}

std::list<Projectile*> Rifle::Shoot(const sf::Vector2f position)
{
	if (this->timer.getElapsedTime() >= this->reloadTime)
	{
		this->timer.restart();
		return{
			Projectile::createProjectile(this->projID, position, this->getDirection(), this->owner)
		};
	}
	return {};
}