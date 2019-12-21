#include "Bullet.h"
Bullet::Bullet(const sf::Vector2f pos, const sf::Vector2f direction, const int hostility)
	: Projectile(direction, 3, hostility, pos, 800.f, "Bullet")
{};

void Bullet::step(const sf::Time dt)
{
	this->move((float)dt.asMicroseconds() / 1000000 * this->getVelocity());
}