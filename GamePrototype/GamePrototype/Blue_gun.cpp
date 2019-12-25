#include "Blue_gun.h"

Blue_gun::Blue_gun(const sf::Vector2f direction)
	: Gun(direction, sf::milliseconds(1000))
{
}

std::list<Projectile*> Blue_gun::shoot(const sf::Vector2f position)
{
	if (!frozen && this->timer.getElapsedTime() >= this->reloadTime)
	{
		this->timer.reset();
		return
		{
			ProjFactory::getProj(position, this->getDirection(), "Blue_bullet")
		};
	}
	else
		return {};
}