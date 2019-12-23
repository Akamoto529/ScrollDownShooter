#include "Missile.h"

Missile::Missile(const sf::Vector2f pos, const sf::Vector2f direction, const int hostility, Entity* target)
	:Projectile(direction, 1, hostility, pos, 200.f, "Missile")
{
	this->target = target;
	this->accuracy = 0.005;
}

void Missile::step(const sf::Time dt)
{
	if (!frozen)
	{
		this->setVelocity(this->getVelocity() + (this->target->getPosition() - this->getPosition()) * accuracy);
		this->move(this->getVelocity() * dt.asSeconds());
	}
}