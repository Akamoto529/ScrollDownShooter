#include "Suicider.h"

Suicider::Suicider(const sf::Vector2f pos, Entity* target)
	: Enemy(pos, 200.f, "Suicider")
{
	this->HP = 3;
	this->target = target;
}

void Suicider::step(const sf::Time dt)
{
	if (!frozen)
	{
		sf::Vector2f velocity = target->getPosition() - this->getPosition();
		velocity /= sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
		this->move(velocity * this->speed * dt.asSeconds());
	}
}