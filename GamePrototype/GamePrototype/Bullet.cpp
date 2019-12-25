#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f pos, const sf::Vector2f direction)
	: Projectile(direction, 1, pos, 1200.f, "Bullet")
{}