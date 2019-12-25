#include "Green_gun.h"

Green_gun::Green_gun(const sf::Vector2f direction)
	: Gun(direction, sf::milliseconds(1500))
{
}

std::list<Projectile*> Green_gun::shoot(const sf::Vector2f position)
{
	if (!frozen && this->timer.getElapsedTime() >= this->reloadTime)
	{
		sf::Vector2f deg30 = sf::Vector2f(this->getDirection().x*cos(30.f/180.f*PI) + this->getDirection().y*sin(30.f/180.f*PI),
			-this->getDirection().x * sin(30.f / 180.f * PI) + this->getDirection().y * cos(30.f / 180.f * PI));
		this->timer.reset();
		return
		{
			ProjFactory::getProj(position, this->getDirection(), "Green_bullet"),
			ProjFactory::getProj(position, sf::Vector2f(deg30.y,deg30.x), "Green_bullet"),
			ProjFactory::getProj(position, sf::Vector2f(-deg30.y,deg30.x), "Green_bullet")
		};
	}
	else
		return {};
}