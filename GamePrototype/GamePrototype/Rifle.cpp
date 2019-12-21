#include "Rifle.h"
Rifle::Rifle(const sf::Vector2f direction, std::string projName, const int hostility)
	: Gun(direction, projName, sf::milliseconds(500), hostility)
{
}

	std::list<Projectile*> Rifle::shoot(const sf::Vector2f position)
	{
		if (this->timer.getElapsedTime() >= this->reloadTime)
		{
			this->timer.restart();
			return{ProjFactory::getProj(position, this->getDirection(), this->hostility,"Bullet")};
		}
		return {};
	}
