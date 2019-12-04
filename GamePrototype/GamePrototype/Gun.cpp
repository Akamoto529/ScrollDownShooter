#include "Gun.h"

Gun::Gun(sf::Vector2f direction)
{
	this->direction = direction;
}

sf::Vector2f Gun::getDirection()
{
	return this->direction;
}

void Gun::setDirection(sf::Vector2f direction)
{
	this->direction = direction;
}

Rifle::Rifle(sf::Vector2f direction, sf::Texture projTx)
	:Gun(direction)
{
	this->reload = sf::milliseconds(500);
	this->projTx = projTx;
	this->timer.restart();
}

std::list<Projectile*> Rifle::Shoot(sf::Vector2f position)
{
	if (this->timer.getElapsedTime() >= this->reload)
	{
		this->timer.restart();
		return std::list<Projectile*>(1
			, new Projectile(this->getDirection(), this->projTx, 0.8f, position));
	}
	return {};
}