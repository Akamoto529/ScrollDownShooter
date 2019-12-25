#include "Missile.h"

Missile::Missile(const sf::Vector2f pos, const sf::Vector2f direction, Entity* target)
	:Projectile(direction, 1, pos, 200.f, "Missile")
{
	this->target = target;
	this->accuracy = 0.01f;
	this->isHoming = true;
}

void Missile::step(const sf::Time dt)
{
	if (!frozen)
	{
		if ((this->target->getPosition() - this->getPosition()).x < 20 && (this->target->getPosition() - this->getPosition()).y < 20)
			isHoming = false;
		if (isHoming)
			this->setVelocity(this->getVelocity() + (this->target->getPosition() - this->getPosition()) * accuracy);
		this->move(this->getVelocity() * dt.asSeconds());
	}
}