#include "Suicider.h"

Suicider::Suicider(const sf::Vector2f pos, Entity* target)
	: Enemy(pos, 150.f, "Suicider")
{
	this->HP = 2;
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

	if (overlay.getElapsedTime() >= sf::milliseconds(MSEC_PER_FRAME * 10))
	{
		this->overlay.reset();
		this->overlay.pause();
		this->setColor(sf::Color(255, 255, 255));
	}
}