#include "Purple_gun.h"

Purple_gun::Purple_gun(const sf::Vector2f direction)
	: Gun(direction, sf::milliseconds(200))
{
}

void Purple_gun::freeze()
{
	this->Gun::freeze();
	this->overheat.pause();
}

void Purple_gun::unfreeze()
{
	this->Gun::unfreeze();
	this->overheat.start();
}

std::list<Projectile*> Purple_gun::shoot(const sf::Vector2f position)
{
	if (overheat.getElapsedTime() >= sf::milliseconds(2000))
		overheat.reset();
	if (!frozen && 
		(timer.getElapsedTime() >= reloadTime) &&
		overheat.getElapsedTime() >= sf::milliseconds(2000 - 3 * reloadTime.asMilliseconds()))
	{
		this->timer.reset();
		return
		{
			ProjFactory::getProj(position, this->getDirection(), "Purple_bullet")
		};
	}
	else
		return {};
}