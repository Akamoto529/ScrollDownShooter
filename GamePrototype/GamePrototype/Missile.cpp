#include "Missile.h"

Missile::Missile(const sf::Vector2f direction, const int hostility, Entity* target, const sf::Vector2f pos)
	:Projectile(direction, 1, hostility, pos, 200.f, "Bullet")
{
	this->target = target;
	this->accuracy = 0.1;
}

void Missile::step(const sf::Time dt)
{
	this->setVelocity(this->getVelocity() + (this->target->getPosition() - this->getPosition()) * accuracy);
	this->move(this->getVelocity() * dt.asSeconds());
}