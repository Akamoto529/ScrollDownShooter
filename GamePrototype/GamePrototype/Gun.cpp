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

Rifle::Rifle(sf::Vector2f direction)
	:Gun(direction)
{
	this->reload = sf::milliseconds(1000);
	this->projTx.loadFromFile("Assets/Projectile.png");
	this->timer.restart();
}

void Rifle::Shoot(Scene* scene, sf::Vector2f position)
{
	if (this->timer.getElapsedTime() >= this->reload)
	{
		Projectile* proj = new Projectile(this->getDirection(), this->projTx, 0.1f, position);
		scene->AddEntity(proj);
		this->timer.restart();
	}
}