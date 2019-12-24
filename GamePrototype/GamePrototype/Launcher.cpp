#include "Launcher.h"

Launcher::Launcher(const sf::Vector2f direction, Entity* target)
	: Gun(direction, sf::milliseconds(2000))
{
	this->target = target;
}

std::list<Projectile*> Launcher::shoot(const sf::Vector2f position)
{
	if (!frozen && this->timer.getElapsedTime() >= this->reloadTime)
	{
		this->timer.reset();
		return
		{
			ProjFactory::getProj(position, this->getDirection(), "Missile", this->target)
		};
	}
	else
		return {};
}