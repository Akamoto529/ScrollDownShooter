#include "Rifle.h"
Rifle::Rifle(const sf::Vector2f direction, std::string projName)
	: Gun(direction, projName, sf::milliseconds(500))
{
}

	std::list<Projectile*> Rifle::shoot(const sf::Vector2f position)
	{
		if (this->timer.getElapsedTime() >= this->reloadTime)
		{
			this->timer.reset();
			return{ProjFactory::getProj(position, this->getDirection(),"Bullet")};
		}
		return {};
	}
