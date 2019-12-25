#include "Rifle.h"

Rifle::Rifle(const sf::Vector2f direction)
	: Gun(direction, sf::milliseconds(250))
{
}

std::list<Projectile*> Rifle::shoot(const sf::Vector2f position)
{
	if (!frozen && this->timer.getElapsedTime() >= this->reloadTime)
	{
		this->timer.reset();
		return
		{
			ProjFactory::getProj(position, this->getDirection(), "Bullet")
		};
	}
	else
		return {};
}