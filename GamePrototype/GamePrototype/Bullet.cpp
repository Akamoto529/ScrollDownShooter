#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f pos, const sf::Vector2f direction)
	: Projectile(direction, 2, pos, 800.f, "Bullet")
{}