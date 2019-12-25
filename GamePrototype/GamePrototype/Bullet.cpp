#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f pos, const sf::Vector2f direction)
	: Projectile(direction, 1, pos, 400.f, "Bullet")
{}

void Bullet::step(const sf::Time dt)
{
	if (!frozen)
		this->move(dt.asSeconds() * this->getVelocity());
}